<template>
    <div class="add-product-container">
        <input type="text" v-model="newProduct.name" placeholder="Product title" required><br>
        <input type="text" v-model.number="newProduct.price" placeholder="Product Price" required><br>
        <input type="text" v-model="newProduct.image" placeholder="picture link of the product" required><br>
        <select v-model="newProduct.category" required>
            <option disabled value="">Select category</option>
            <option value="women">Women</option>
            <option value="men">Men</option>
            <option value="kids">Kids</option>
            <option value="general">General</option>
        </select>
        <button @click="addProduct">Add Product</button>
    </div>
</template>
<script>
export default {
    data() {
        return {
            newProduct: {
                "flag":true,
                "name": '',
                "price": 0,
                "category": '',
                "image": ''
            }
        }
    },
    methods: {
        async addProduct() {
             await fetch('http://localhost:3000/products', {
                method: 'POST',
                headers: { 'Content-Type': 'application/json' },
                body: JSON.stringify(this.newProduct)
            })
            .then(resp => resp.json())
            .then(data => {
                alert("Product added");
            });
        }
    }
}
</script>
<style scoped>
.add-product-container {
    max-width: 350px;
    margin: 60px auto;
    padding: 30px 24px;
    background: #f9f9fc;
    border-radius: 10px;
    box-shadow: 0 2px 8px #0001;
    text-align: center;
}
.add-product-container input,
.add-product-container select {
    width: 90%;
    padding: 10px;
    margin: 10px 0;
    border: 1px solid #bbb;
    border-radius: 5px;
    font-size: 1em;
}
.add-product-container button {
    width: 95%;
    padding: 10px;
    margin-top: 15px;
    background: #1976d2;
    color: #fff;
    border: none;
    border-radius: 5px;
    font-size: 1em;
    cursor: pointer;
    transition: background 0.2s;
}
.add-product-container button:hover {
    background: #0d47a1;
}
</style>