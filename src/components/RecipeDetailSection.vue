<template>
  <div class="recipe-detail-section">
    <h2>{{ recipe.title }}</h2>
    <h3>Ingredients</h3>
    <ul>
      <li v-for="ingredient in recipe.ingredients" :key="ingredient">{{ ingredient }}</li>
    </ul>
    <h3>Instructions</h3>
    <p>{{ recipe.instructions }}</p>
  </div>
</template>

<script>
export default {
  name: 'RecipeDetailSection',
  props: {
    recipe: {
      type: Object,
      required: true
    }
  }
}
</script>

<style scoped>
.recipe-detail-section {
  padding: 20px;
  border: 1px solid #ccc;
  border-radius: 5px;
  background-color: #f9f9f9;
}
</style>