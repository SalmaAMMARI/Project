<template>
  <div class="dashboard-container">
    <router-link to="/women" class="dashboard-link">Women Products</router-link>
    <router-link to="/kids" class="dashboard-link">Kids Products</router-link>
    <router-link to="/men" class="dashboard-link">Men Products</router-link>
    <router-link to="/general" class="dashboard-link">General Products</router-link>
    <router-link to="/panier" class="dashboard-link">Panier</router-link>
    <br>
    <router-link to="/addPro" class="dashboard-link">Add a product to sell it</router-link>
    <router-link to="/" class="dashboard-link">Log Out</router-link>
  </div>
</template>
<script>


</script>
<style scoped>
.dashboard-container {
    max-width: 350px;
    margin: 60px auto;
    padding: 30px 24px;
    background: #f9f9fc;
    border-radius: 10px;
    box-shadow: 0 2px 8px #0001;
    text-align: center;
}
.dashboard-link {
    display: block;
    margin: 12px 0;
    padding: 10px 0;
    color: #1976d2;
    background: #fff;
    border-radius: 5px;
    text-decoration: none;
    font-size: 1.1em;
    transition: background 0.2s, color 0.2s;
    box-shadow: 0 1px 4px #0001;
}
.dashboard-link:hover {
    background: #1976d2;
    color: #fff;
}
</style>