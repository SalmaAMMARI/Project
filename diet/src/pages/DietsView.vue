<template>
  <div class="diets-view">
    <h1>Régimes alimentaires</h1>
    <div class="diet-cards">
      <DietCard v-for="diet in diets" :key="diet.id" :diet="diet" />
    </div>
  </div>
</template>

<script>
import DietCard from '../components/DietCard.vue';

export default {
  name: 'DietsView',
  components: {
    DietCard
  },
  data() {
    return {
      diets: []
    };
  },
  mounted() {
    fetch('http://localhost:3000/regimes')
      .then(response => response.json())
      .then(data => {
        this.diets = data;
      })
      .catch(error => {
        console.error('Erreur lors du chargement des régimes :', error);
      });
  }
};
</script>

<style scoped>
.diet-cards {
  display: flex;
  flex-wrap: wrap;
}
</style>