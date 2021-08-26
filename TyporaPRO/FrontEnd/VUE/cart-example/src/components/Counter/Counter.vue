<template>
  <div class="number-container d-flex justify-content-center align-items-center">
    <!-- 减 1 的按钮 -->
    <button type="button" class="btn btn-light btn-sm" @click="sub">-</button>
    <!-- 购买的数量 -->
    <span class="number-box">{{ count }}</span>
    <!-- 加 1 的按钮 -->
    <button type="button" class="btn btn-light btn-sm" @click="add">+</button>
  </div>
</template>

<script>
export default {
  props:{
    id:{
      default:0,
      type:Number
    },
    cou:{
      default: 0,
      type:Number
    }
  },
  data(){
    return {
      count:this.cou
    }
  },
  methods:{
    add(){
      this.count++
      this.$emit("addCount",{id : this.id,val:this.count})
    },
    sub(){
      if(this.count>0){
        this.count--
        this.$emit("subCount",{id : this.id,val:this.count})
      }
    }
  }
}
</script>

<style lang="less" scoped>
.number-box {
  min-width: 30px;
  text-align: center;
  margin: 0 5px;
  font-size: 12px;
}

.btn-sm {
  width: 30px;
}
</style>
