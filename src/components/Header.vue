<template>
  <header>
    
    <nav>
      <ul>
        <li><router-link to="/">Accueiil</router-link></li>
        <li><router-link to="/recipes">Recettes</router-link></li>
        <li><router-link to="/diets">Regimes</router-link></li>
      </ul>
    </nav>
  </header>
</template>

<script>
export default {
  name: 'Header'
}
</script>

<style scoped>
header {
  background-color: #f8f9fa;
  padding: 1rem;
  text-align: center;
}

nav ul {
  list-style-type: none;
  padding: 0;
}

nav ul li {
  display: inline;
  margin: 0 1rem;
}
</style>