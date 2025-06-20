<template>
  <div class="signup-form">
    <h2>Sign Up</h2>
    <input v-model="username" type="text" placeholder="Username" required>
    <input v-model="password" type="password" placeholder="Password" required>
    <input v-model="confirmPassword" type="password" placeholder="Confirm Password" required>
    <button @click="handleSignup">Sign Up</button>
    <p class="toggle-form" @click="goToLogin">Already have an account? Login</p>
    <p v-if="error" class="error">{{ error }}</p>
  </div>
</template>

<script>
export default {
  name: 'Signup',
  data() {
    return {
      username: '',
      password: '',
      confirmPassword: '',
      error: ''
    }
  },
  methods: {
    handleSignup() {
      if (!this.username || !this.password || !this.confirmPassword) {
        this.error = 'Please fill all fields'
        return
      }

      if (this.password !== this.confirmPassword) {
        this.error = 'Passwords do not match'
        return
      }

      const users = JSON.parse(localStorage.getItem('users')) || []

      if (users.some(u => u.username === this.username)) {
        this.error = 'Username already exists'
        return
      }

      const newUser = {
        username: this.username,
        password: this.password
      }

      users.push(newUser)
      localStorage.setItem('users', JSON.stringify(users))
      localStorage.setItem('currentUser', JSON.stringify(newUser))
      this.$router.push('/dash')
    },
    goToLogin() {
      this.$router.push('/logIn')
    }
  }
}
</script>

<style scoped>
.error {
  color: red;
  text-align: center;
}
</style>