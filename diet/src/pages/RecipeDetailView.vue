<template>
  <div class="recipe-detail-view">
    <RecipeDetailSection :recipe="recipe" />
  </div>
</template>

<script>
import RecipeDetailSection from '../components/RecipeDetailSection.vue';

export default {
  name: 'RecipeDetailView',
  components: {
    RecipeDetailSection
  },
  data() {
    return {
      recipe: {} // This will hold the recipe details
    };
  },
  created() {
    // Fetch the recipe details based on the route parameter
    const recipeId = this.$route.params.id;
    this.fetchRecipeDetails(recipeId);
  },
  methods: {
    fetchRecipeDetails(id) {
      // Simulate an API call to fetch recipe details
      // In a real application, you would replace this with an actual API call
      this.recipe = {
        id: id,
        title: 'Sample Recipe',
        ingredients: ['Ingredient 1', 'Ingredient 2'],
        instructions: 'Step 1: Do this. Step 2: Do that.'
      };
    }
  }
};
</script>

<style scoped>
.recipe-detail-view {
  padding: 20px;
}
</style>