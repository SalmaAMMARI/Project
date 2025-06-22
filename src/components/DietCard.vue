<template>
  <div class="diet-card">
    <img :src="diet.image" :alt="diet.name" class="diet-image" />
    <h3>{{ diet.name }}</h3>
    <p>{{ diet.description }}</p>
    <div>
      <strong>Aliments autorisés :</strong>
      <ul>
        <li v-for="item in diet.allowed" :key="item">{{ item }}</li>
      </ul>
    </div>
    <div v-if="diet.forbidden && diet.forbidden.length">
      <strong>Aliments interdits :</strong>
      <ul>
        <li v-for="item in diet.forbidden" :key="item">{{ item }}</li>
      </ul>
    </div>
    <button @click="goToRecipes">Voir les recettes compatibles</button>
  </div>
</template>

<script>
export default {
  name: 'DietCard',
  props: {
    diet: {
      type: Object,
      required: true
    }
  },
  methods: {
    goToRecipes() {
      this.$router.push({ path: '/recipes', query: { regime: this.diet.id } });
    }
  }
};
</script>
<style scoped>
.diet-card {
  border: 1px solid #ccc;
  border-radius: 5px;
  padding: 10px;
  margin: 10px;
  max-width: 300px;
}
.diet-image {
  width: 100%;
  border-radius: 3px;
}
button {
 
  background: #4caf50;
  color: #fff;
  border: none;
  border-radius: 3px;
 
}
</style>