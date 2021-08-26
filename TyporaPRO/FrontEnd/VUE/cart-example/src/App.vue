<template>
  <div class="app-container">
<!--头部信息-->
    <Header></Header>
<!--    内容区域-->
    <Goods
        v-for="item in cartList"
        :key="item.id"
        :id="item.id"
        :title="item.goods_name"
        :img="item.goods_img"
        :price="item.goods_price"
        :status="item.goods_state"
        :count="item.goods_count"
        @changeStatus="changeStatus"
        @addCount="addCount"
        @subCount="subCount"
    ></Goods>

<!--    底部-->
    <Footer :isFull="fullStatus" :allCount="allCount" :computAll="computAll"  @fullChange="fullChange"></Footer>
  </div>
</template>

<script>
import axios from "axios"
import Header from "@/components/Header/Header";
import Goods from "@/components/Goods/Goods"
import Footer from "@/components/Footer/Footer";
export default {
  components:{
    Header,
    Goods,
    Footer
  },
  data(){
    return{
      cartList:[]
    }
  },
  computed : {
    fullStatus(){

      // return this.cartList.every(function (item){
      //    return item.goods_state ==true
      // })
    //  简写
      return this.cartList.every(item=>item.goods_state)
    },
    computAll(){
      let sum = 0;
      this.cartList.forEach(function (item){
        if (item.goods_state===true){
          sum += (item.goods_count * item.goods_price)
        }
      })
      console.log(sum)
      return sum
    },
    allCount(){
      let sum = 0;
      this.cartList.forEach(function (item){
        if (item.goods_state===true){
          sum += 1
        }
      })
      console.log(sum)
      return sum
    }
  },
  methods:{
    async initCartList(){
      const {data : res }= await axios.get("https://www.escook.cn/api/cart")
      if (res.status===200){
        this.cartList = res.list
      }
      console.log(this.cartList)
    },
    changeStatus(data){

      this.cartList.some(item =>{
        if (item.id === data.id){
          item.goods_state = data.val
          return
        }
      })
      console.log(data)
      console.log(this.cartList)
    },
    fullChange(data){
      this.cartList.forEach(item=>item.goods_state=data)
    },
    addCount(data){
      console.log(data)
      this.cartList.some(function (item){
        if (item.id === data.id){
          item.goods_count = data.val
        }
      })
    },
    subCount(data){
      this.cartList.some(function (item){
        if (item.id === data.id){
          item.goods_count = data.val
        }
      })
    }
  },
  created() {
    this.initCartList()
  }

}
</script>
<style lang="less" scoped>
.app-container {
  padding-top: 45px;
  padding-bottom: 50px;
}
</style>
