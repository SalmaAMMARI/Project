import { createRouter, createWebHistory } from 'vue-router'
import HomeView from '../pages/HomeView.vue'
import RecipesView from '../pages/RecipesView.vue'
import RecipeDetailView from '../pages/RecipeDetailView.vue'
import DietsView from '../pages/DietsView.vue'

const routes = [
  { path: '/', component: HomeView },
  { path: '/recipes', component: RecipesView },
  { path: '/recipes/:id', component: RecipeDetailView },
  { path: '/diets', component: DietsView }
]

const router = createRouter({
  history: createWebHistory(),
  routes
})

export default router