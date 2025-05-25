<template>
    <div>
        <h2>Men Products</h2>
        <input type="text" placeholder="Search for a product" v-model="search" >
        <div v-for="product in filtered" :key="product.id">
            <div v-if="product.category==='men'">
                <img :src="require('@/assets/'+product.image)"><br>
                {{ product.name }}<br>
                {{ product.price }}$<br>
                <button @click="ajouter(product)">Add to the bucket</button>
                <button @click="supp(product)" v-if="product.flag"> delete your product</button>
                


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
            return this.products.filter(product=>product.name.toLowerCase().includes(this.search.toLowerCase()) && product.category==="men")
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