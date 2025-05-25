<template>
  <div class="signup-container">
    <router-link to="/logIn" class="signup-link">Go to log in if u already have an account</router-link>
    <input type="text" v-model="newUser.name" placeholder="your name" required class="signup-input">
    <input type="email" v-model="newUser.email" placeholder="your email" required class="signup-input">
    <button @click="SignUp" class="signup-btn">Sign up</button>
  </div>
</template>
<script>
export default{
    data(){
        return{
            newUser:{
                 "name":"",
            "email":""

            },
           
            users:[]
        }
    }, created(){
        fetch('/data.json')
        .then(response=>response.json())
        .then(data =>{
            this.users = data.users
        })
    },
    methods:{
        SignUp(){
            const exists = this.users.some(user=>user.email===this.newUser.email);
            if (exists){
                alert('this email already exists')
            }else{
                fetch('http://localhost:3000/users', {
                    method:'POST',
                    headers:{
                        'Content-Type': 'application/json'
                    },
                    body :JSON.stringify(this.newUser)
                })
                .then(resp=>resp.json())
                .then(data=>{
                    alert("U are registered successfully");
                    this.$router.push('/dash');
                })
            }

        }
    }
}
</script>
<style scoped>
.signup-container {
  max-width: 350px;
  margin: 60px auto;
  padding: 30px 24px;
  background: #f9f9fc;
  border-radius: 10px;
  box-shadow: 0 2px 8px #0001;
  text-align: center;
}
.signup-input {
  width: 90%;
  padding: 10px;
  margin: 10px 0;
  border: 1px solid #bbb;
  border-radius: 5px;
  font-size: 1em;
}
.signup-btn {
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
.signup-btn:hover {
  background: #0d47a1;
}
.signup-link {
  display: block;
  margin-bottom: 18px;
  color: #1976d2;
  text-decoration: none;
}
.signup-link:hover {
  text-decoration: underline;
}
</style>