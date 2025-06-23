<template>
  <div class="recipe-filter">
    <h2>Filtrer les recettes</h2>
    <select v-model="selectedCategory" @change="emitFilter">
      <option value="">toutes les catégories</option>
      <option v-for="category in categories" :key="category" :value="category">{{ category }}</option>
    </select>
    <input type="text" v-model="searchQuery" @input="emitFilter" placeholder="chercher les recetes" />
    <input type="number" min="0" v-model.number="maxTime" @input="emitFilter" placeholder="Durée max (min)" />
  </div>
</template>

<script>
export default {
  props: {
    categories: {
      type: Array,
      required: true
    }
  },
  data() {
    return {
      selectedCategory: '',
      searchQuery: '',
      maxTime: null
    };
  },
  methods: {
    emitFilter() {
      this.$emit('filter', {
        category: this.selectedCategory,
        query: this.searchQuery,
        maxTime: this.maxTime
      });
    }
  }
};
</script>

<style scoped>
.recipe-filter {
  margin: 20px 0;
  display: flex;
  gap: 10px;
  align-items: center;
}
</style>