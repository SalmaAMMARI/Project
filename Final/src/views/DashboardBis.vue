<template>
  <div class="home">
    <router-link to="/panier">Go to the panier</router-link>
    <div v-for="product in filtered" :key="product.id">
      <img :src="require('@/assets/'+product.image)"><br>
      {{ product.name }}
    <br>
    {{ product.price }}<br>
    <button @click="add(product)">Add product</button>
    <button @click="supp(product)">Delete the product</button>
    <textarea v-if="flag" v-model="commentaire">Add ur comment</textarea>
    <button @click="ajouter(product)" v-if="flag">Ajouter le commentaire</button>
    <button @click="afficher()">Add a review</button>

    </div>
    
  </div>
</template>

<script>
import global from '../views/Global.js'
export default{
  data(){
    return {
      products:[],
      flag:false,
      commentaire:"",
     
      
    }
  },created(){
    fetch('/data.json')
    .then(resp=>resp.json())
    .then(data=>
      this.products=data.products
    )
  },
  computed:{
    filtered(){
      return this.products.filter(product=>product.category==='women')
    }
  },
  methods:{
     add(product) {
            global.sum += product.price
            global.panier.push(product)
        },
        async supp(product){
            await fetch(`http://localhost:3000/products/${product.id}`, {method:'DELETE'},)
            .then(resp=>resp.json())
            .then(resp=>{ if (resp.ok){
                    this.products=this.products.filter(p=>p.id!==product.id)
                    alert("deleted!")
                }}
               
            )


        },
        afficher(){
            this.flag=!this.flag
        }
        ,
        async ajouter(product){
            this.flag=true
            await fetch(`http://localhost:3000/products/${product.id}`,{
                method:'PATCH',
                headers:{
                    'Content-type':'application/json'
                },
                body: JSON.stringify({
                    commentaire:this.commentaire
                })
            })
            .then(resp=>resp.json)
            .then(resp=>{
                if (resp.ok){
                    product.commentaire=this.commentaire
                    alert("comment added")
                        this.flag=false
                        this.commentaire=""
                    
                }
                
            })



        }
  }
}

</script>
