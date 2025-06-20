<template>
  <div class="login-form">
    <h2>Login</h2>
    <input v-model="username" type="text" placeholder="Username" required>
    <input v-model="password" type="password" placeholder="Password" required>
    <button @click="handleLogin">Login</button>
    <p class="toggle-form" @click="goToSignup">Don't have an account? Sign up</p>
    <p v-if="error" class="error">{{ error }}</p>
  </div>
</template>

<script>
export default {
  name: 'Login',
  data() {
    return {
      username: '',
      password: '',
      error: ''
    }
  },
  methods: {
    handleLogin() {
      if (!this.username || !this.password) {
        this.error = 'Please fill all fields'
        return
      }

      const users = JSON.parse(localStorage.getItem('users')) || []
      const user = users.find(u => u.username === this.username && u.password === this.password)

      if (user) {
        localStorage.setItem('currentUser', JSON.stringify(user))
        this.$router.push('/dash')
      } else {
        this.error = 'Invalid username or password'
      }
    },
    goToSignup() {
      this.$router.push('/signup')
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