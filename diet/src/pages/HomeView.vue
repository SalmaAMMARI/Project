<template>
  <div class="home-view">
    <h1>Bienvenues dans Recettees App</h1>

    <router-link to="/recipes">Voir les recettes</router-link>&nbsp;&nbsp;
    <router-link to="/diets">Voir les régimes</router-link>
  </div>
</template>

<script>
export default {
  name: 'HomeView'
}
</script>

<style scoped>
.home-view {
  text-align: center;
  margin-top: 50px;
}
</style>