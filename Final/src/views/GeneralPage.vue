<template>
    <div class="general-container">
        <h2>General Products</h2>
          <input type="text" placeholder="Search for a product" v-model="search" >
        <div class="products-wrapper">
            <div v-for="product in filtered" :key="product.id" class="product-card">
                <div v-if="product.category==='general'">
                    <img :src="require('@/assets/'+product.image)" class="product-img"><br>
                    <span class="product-name">{{ product.name }}</span><br>
                    <span class="product-price">{{ product.price }}$</span><br>
                    <button @click="ajouter(product)" class="add-btn">Add to the bucket</button>
                    <button @click="supp(product)" v-if="product.flag" class="delete-btn"> delete your product</button>
                </div>
            </div>
        </div>
    </div>
</template>
<script>
import global from './Global.js'
export default{
    data(){
        return {
            products:[],
            search:''
            
        }
    }, created(){
        fetch('/data.json')
        .then(response=>response.json())
        .then(data=>
            this.products=data.products
        )
    },computed:{
        filtered(){
            return this.products.filter(product=>product.name.toLowerCase().includes(this.search.toLowerCase()) && product.category==="general")
        }
    },
    methods:{
        ajouter(product){
            global.sum+=product.price
            global.panier.push(product)
            alert("product added to the bucket")
        },
        async supp(product){
           await  fetch(`http://localhost:3000/products/${product.id}`,{
                method:'DELETE',

            })
            .then(response =>{
                if (response.ok){
                    this.products=this.products.filter(p=>p.id!==product.id)
                    alert("product deleted")
                }
                }
            )
        }
    }
}
</script>

<style scoped>

</style>