<template>
    <div class="kid-container">
        <h2>Kids Products</h2>
        <input type="text" placeholder="Search for a product" v-model="search" class="search-input">
        <div v-for="product in filtered" :key="product.id" class="product-card">
            <img :src="require('@/assets/'+product.image)" class="product-img"><br>
            <span class="product-name">{{ product.name }}</span><br>
            <span class="product-price">{{ product.price }}$</span><br>
            <button @click="ajouter(product)" class="add-btn">Add to the bucket</button>
            <button @click="supp(product)" v-if="product.flag" class="delete-btn">Delete your product</button>
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
            return this.products.filter(product=>product.name.toLowerCase().includes(this.search.toLowerCase()) && product.category==="kids")
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
.kid-container {
    max-width: 700px;
    margin: 30px auto;
    padding: 20px;
    background: #f9f9fc;
    border-radius: 10px;
    box-shadow: 0 2px 8px #0001;
    text-align: center;
}
.search-input {
    width: 60%;
    padding: 8px;
    margin-bottom: 20px;
    border: 1px solid #bbb;
    border-radius: 5px;
}
.product-card {
    display: inline-block;
    width: 180px;
    margin: 15px;
    padding: 15px;
    background: #fff;
    border-radius: 8px;
    box-shadow: 0 1px 4px #0001;
    vertical-align: top;
}
.product-img {
    width: 100px;
    height: 100px;
    object-fit: cover;
    border-radius: 6px;
    margin-bottom: 10px;
}
.product-name {
    font-weight: bold;
    color: #333;
}
.product-price {
    color: #2a7;
    font-size: 1.1em;
}
.add-btn, .delete-btn {
    margin: 6px 2px;
    padding: 6px 12px;
    border: none;
    border-radius: 4px;
    cursor: pointer;
}
.add-btn {
    background: #4caf50;
    color: #fff;
}
.delete-btn {
    background: #e53935;
    color: #fff;
}
.add-btn:hover {
    background: #388e3c;
}
.delete-btn:hover {
    background: #b71c1c;
}
</style>