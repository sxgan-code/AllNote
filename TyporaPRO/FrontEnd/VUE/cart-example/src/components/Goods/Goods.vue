<template>
  <div class="goods-container">
    <!-- 左侧图片 -->
    <div class="thumb">
      <div class="custom-control custom-checkbox">
        <!-- 复选框 -->
        <input type="checkbox" class="custom-control-input" id="cb1" :checked="status" @click="changeStatus" />
        <label class="custom-control-label" for="cb1">
          <!-- 商品的缩略图 -->
          <img :src="img" alt="" />
        </label>
      </div>
    </div>
    <!-- 右侧信息区域 -->
    <div class="goods-info">
      <!-- 商品标题 -->
      <h6 class="goods-title">{{ title }}</h6>
      <div class="goods-info-bottom">
        <!-- 商品价格 -->
        <span class="goods-price">￥{{ price }}</span>
        <!-- 商品的数量 -->
        <Counter :id="id" :cou="count" @addCount="addCount" @subCount="subCount"></Counter>
      </div>
    </div>
  </div>
</template>

<script>
import Counter from "@/components/Counter/Counter";
export default {
  components:{
    Counter
  },
  props:{
    id:{
      default:0,
      type:Number
    },
    title:{
      default:'',
      type:String
    },
    price:{
      default: 0,
      type:Number
    },
    img:{
      default: '',
      type:String
    },
    status:{
      default:true,
      type:Boolean
    },
    count:{
      default: 0,
      type:Number
    }


  },
  methods:{
    changeStatus(e){
      this.$emit("changeStatus",{id:this.id,val:e.target.checked})
    },
    addCount(data){
      this.$emit("addCount",data)
    },
    subCount(data){
      this.$emit("subCount",data)
    }
  }
}
</script>

<style lang="less" scoped>
.goods-container {
  + .goods-container {
    border-top: 1px solid #efefef;
  }
  padding: 10px;
  display: flex;
  .thumb {
    display: flex;
    align-items: center;
    img {
      width: 100px;
      height: 100px;
      margin: 0 10px;
    }
  }

  .goods-info {
    display: flex;
    flex-direction: column;
    justify-content: space-between;
    flex: 1;
    .goods-title {
      font-weight: bold;
      font-size: 12px;
    }
    .goods-info-bottom {
      display: flex;
      justify-content: space-between;
      .goods-price {
        font-weight: bold;
        color: red;
        font-size: 13px;
      }
    }
  }
}
</style>
