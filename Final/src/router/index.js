import { createRouter, createWebHistory } from 'vue-router'
import HomeView from '../components/Hompage.vue'
import dash from  '../components/Dashboard.vue'
import women from '../views/WomenPage.vue'
import men from '../views/MenPage.vue'
import kids from '../views/KidPage.vue'
import general from '../views/GeneralPage.vue'
import panier from '../views/PanierPage.vue'
import add from '../views/AddProduct.vue'
import signup from '../views/SignUp.vue'
import login from '../views/LogIn.vue'

const routes = [
  {
    path: '/',
    name: 'home',
    component: HomeView
  },
   {
    path: '/dash',
    name: 'dashboard',
    component:dash 
  },
   {
    path: '/women',
    name: 'womenPage',
    component:women
  },
   {
    path: '/men',
    name: 'menPage',
    component:men
  },
   {
    path: '/kids',
    name: 'KidsPage',
    component:kids 
  },
   {
    path: '/general',
    name: 'generalPage',
    component:general
  },
   {
    path: '/panier',
    name: 'Panier',
    component:panier
  },
   {
    path: '/addPro',
    name: 'AddProduct',
    component:add
  },
   {
    path: '/signUp',
    name: 'SignUp',
    component:signup
  },
   {
    path: '/logIn',
    name: 'LogIn',
    component:login
  }
]

const router = createRouter({
  history: createWebHistory(process.env.BASE_URL),
  routes
})

export default router
