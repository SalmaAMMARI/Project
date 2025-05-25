<template>
    <div class="women-container">
        <h2>Women Products</h2>
        <input type="text" placeholder="Search for a product" v-model="search" class="search-input">
        <div v-for="product in filtered" :key="product.id" class="product-card">
            <img :src="require('@/assets/'+product.image)" alt="product image" class="product-img"><br><br>
            <span class="product-name">{{ product.name }}</span><br>
            <span class="product-price">{{ product.price }}$</span><br>
            <button @click="add(product)" class="add-btn">Add Product</button><br>
            <button @click="supp(product)" v-if="product.flag" class="delete-btn">Delete your product</button>
        </div>
    </div>
</template>
<script>
import global from '../views/Global.js'

export default {
    data() {
        return {
            products: [],
            search:''
        }
    },
    created() {
        fetch('/data.json')  
            .then(res => res.json())
            .then(data => {
                this.products = data.products
            })
            
    },computed:{
        filtered(){
            return this.products.filter(product=>product.name.toLowerCase().includes(this.search.toLowerCase()) && product.category==="women")
        }
    },
    methods: {
        add(product) {
            global.sum += product.price
            global.panier.push(product)
        },
        async supp(product){
           await fetch(`http://localhost:3000/products/${product.id}`,{
                method:'DELETE',
            })
            .then(resp=>{
                if (resp.ok){
                    this.products=this.products.filter(p=>p.id!==product.id)
                    alert("Product deleted successfully")
                }
            })

        }
    }
}
</script>
<style scoped>
.women-container {
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
    color: #e91e63;
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
    background: #1976d2;
    color: #fff;
}
.delete-btn {
    background: #e53935;
    color: #fff;
}
.add-btn:hover {
    background: #0d47a1;
}
.delete-btn:hover {
    background: #b71c1c;
}
</style>