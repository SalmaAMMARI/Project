<template>
    <div class="panier-container">
        <h1>Total Price: {{ sum }}$</h1>
        <h2>Articles</h2>
        <div v-for="product in panier" :key="product.id" class="panier-product">
            <img :src="require('@/assets/'+product.image)" />
            <div class="product-name">{{ product.name }}</div>
            <div class="product-price">{{ product.price }}$</div>
            <button @click="deleter(product)" class="delete-btn">Delete Product</button>
        </div>
    </div>
</template>

<script>
import global from '@/views/Global.js'
export default {
    data() {
        return {
            panier: global.panier,
            sum: global.sum
        }
    },
    methods: {
        deleter(product) {
            global.sum -= product.price
            const index = global.panier.indexOf(product)
            if (index !== -1) {
                global.panier.splice(index, 1)
            }
            this.panier = global.panier
            this.sum = global.sum
        }
    }
}
</script>
<style scoped>
.panier-container {
    max-width: 700px;
    margin: 30px auto;
    padding: 20px;
    background: #f9f9fc;
    border-radius: 10px;
    box-shadow: 0 2px 8px #0001;
    text-align: center;
}
.panier-product {
    display: inline-block;
    width: 180px;
    margin: 15px;
    padding: 15px;
    background: #fff;
    border-radius: 8px;
    box-shadow: 0 1px 4px #0001;
    vertical-align: top;
}
.panier-product img {
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
.delete-btn {
    margin: 8px 0 0 0;
    padding: 6px 12px;
    border: none;
    border-radius: 4px;
    background: #e53935;
    color: #fff;
    cursor: pointer;
}
.delete-btn:hover {
    background: #b71c1c;
}
</style>