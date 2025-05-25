<template>
  <div class="home-container">
    <h1>Welcome to Shopping App</h1>
    
    <h2>Sign Up if you don't have an account</h2>
    <router-link to="/signUp" class="home-link">Sign up</router-link>
  </div>
</template>
<script>
</script>
<style scoped>
.home-container {
  max-width: 400px;
  margin: 80px auto;
  padding: 32px 24px;
  background: #f9f9fc;
  border-radius: 12px;
  box-shadow: 0 2px 8px #0001;
  text-align: center;
}
.home-link {
  display: inline-block;
  margin: 12px 0;
  padding: 10px 24px;
  color: #1976d2;
  background: #fff;
  border-radius: 5px;
  text-decoration: none;
  font-size: 1.1em;
  transition: background 0.2s, color 0.2s;
  box-shadow: 0 1px 4px #0001;
}
.home-link:hover {
  background: #1976d2;
  color: #fff;
}
</style>