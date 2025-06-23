<template>
  <div class="recipe-card">
    <h2>{{ recipe.title }}</h2>
    <img :src="recipe.image" alt="Recipe Image" />
    <p>{{ recipe.description }}</p>
    <p><strong>Temps :</strong> {{ recipe.time }} min</p>
    <p><strong>Difficulté :</strong> {{ recipe.difficulty }}</p>
    <p><strong>Catégorie :</strong> {{ recipe.category }}</p>
    <p><strong>Régime :</strong> {{ recipe.regimes }}</p>
    <p><strong>Auteur :</strong> {{ recipe.author }}</p>
    <button @click="viewRecipe">View Recipe</button>
  </div>
</template>

<script>
export default {
  name: 'RecipeCard',
  props: {
    recipe: {
      type: Object,
      required: true
    }
  },
  methods: {
    viewRecipe() {
      this.$router.push(`/recipes/${this.recipe.id}`);
    }
  }
}
</script>

<style scoped>
.recipe-card {
  border: 1px solid #ccc;
  border-radius: 8px;
  padding: 16px;
  margin: 16px;
  text-align: center;
}
.recipe-card img {
  max-width: 100%;
  height: auto;
  border-radius: 4px;}
  </style>