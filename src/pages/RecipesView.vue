<template>
  <div class="recipes-view">
    <h1>Recettes</h1>
    <RecipeFilter :categories="categories" @filter="applyFilter" />
    <div class="recipe-list">
      <RecipeCard v-for="recipe in filteredRecipes" :key="recipe.id" :recipe="recipe" />
    </div>
  </div>
</template>

<script>
import RecipeCard from '../components/RecipeCard.vue';
import RecipeFilter from '../components/RecipeFilter.vue';

export default {
  name: 'RecipesView',
  components: {
    RecipeCard,
    RecipeFilter
  },
  data() {
    return {
      recipes: [],
      filteredRecipes: [],
      filter: {
        category: '',
        query: '',
        maxTime: null
      }
    };
  },
  computed: {
    categories() {
      const cats = this.recipes.map(r => r.category).filter(Boolean);
      return [...new Set(cats)];
    }
  },
  watch: {
    // Si l'URL change (ex: /recipes?regime=vegetarien), on filtre automatiquement
    '$route.query.regime': {
      immediate: true,
      handler(newRegime) {
        if (newRegime) {
          this.filteredRecipes = this.recipes.filter(recipe =>
            Array.isArray(recipe.regimes) && recipe.regimes.includes(newRegime)
          );
        } else {
          this.filteredRecipes = this.recipes;
        }
      }
    }
  },
  mounted() {
    this.fetchRecipes();
  },
  methods: {
    fetchRecipes() {
      fetch('http://localhost:3000/recipes')
        .then(response => response.json())
        .then(data => {
          this.recipes = data;
          // Appliquer le filtre régime si présent dans l'URL
          const regime = this.$route.query.regime;
          if (regime) {
            this.filteredRecipes = data.filter(recipe =>
              Array.isArray(recipe.regimes) && recipe.regimes.includes(regime)
            );
          } else {
            this.filteredRecipes = data;
          }
        });
    },
    applyFilter(filter) {
      this.filter = filter;
      this.filteredRecipes = this.recipes.filter(recipe => {
        const matchCategory = !filter.category || recipe.category === filter.category;
        const matchQuery = !filter.query || (recipe.title && recipe.title.toLowerCase().includes(filter.query.toLowerCase()));
        const matchTime = !filter.maxTime || (recipe.time && Number(recipe.time) <= Number(filter.maxTime));
        // Si un régime est dans l'URL, on filtre aussi dessus
        const regime = this.$route.query.regime;
        const matchRegime = !regime || (Array.isArray(recipe.regimes) && recipe.regimes.includes(regime));
        return matchCategory && matchQuery && matchTime && matchRegime;
      });
    }
  }
};
</script>

<style scoped>
.recipe-list {
  display: flex;
  flex-wrap: wrap;
  gap: 20px;
}
</style>