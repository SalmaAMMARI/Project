<template>
  <div class="login-container">
    <h2>Log In</h2>
    <input type="text" placeholder="name" v-model="User.name" required class="login-input">
    <input type="email" placeholder="email" v-model="User.email" required class="login-input">
    <button @click="LogIn()" class="login-btn">Log In</button>
  </div>
</template>

<script>
export default {
  data() {
    return {
      User: {
        name: "",
        email: ""
      },
      users: []
    }
  },
  created() {
    fetch("/data.json")
      .then(response => response.json())
      .then(data => {
        this.users = data.users
      })
  },
  methods: {
    LogIn() {
      const exist = this.users.some(
        user =>
          user.name.toLowerCase() === this.User.name.toLowerCase() &&
          user.email.toLowerCase() === this.User.email.toLowerCase()
      );
      if (exist) {
        alert("Welcome " + this.User.name);
        this.$router.push('/dash');
      } else {
        alert("No user with such name and email!");
      }
    }
  }
}
</script>

<style scoped>
.login-container {
  max-width: 350px;
  margin: 60px auto;
  padding: 30px 24px;
  background: #f9f9fc;
  border-radius: 10px;
  box-shadow: 0 2px 8px #0001;
  text-align: center;
}
.login-input {
  width: 90%;
  padding: 10px;
  margin: 10px 0;
  border: 1px solid #bbb;
  border-radius: 5px;
  font-size: 1em;
}
.login-btn {
  width: 95%;
  padding: 10px;
  margin-top: 15px;
  background: #4caf50;
  color: #fff;
  border: none;
  border-radius: 5px;
  font-size: 1em;
  cursor: pointer;
  transition: background 0.2s;
}
.login-btn:hover {
  background: #388e3c;
}
</style>