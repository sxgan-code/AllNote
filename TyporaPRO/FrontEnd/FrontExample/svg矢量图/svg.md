```
public GlobalInput queryCurrentGI(HttpServletRequest request) {
        // TODO Auto-generated method stub
        GlobalInput GI = null;
        Object tempGI = request.getSession().getAttribute("GI");
        // 如果是测试环境，组织假数据返回
        if ((SysConst.isDevelopment() && CommonUtil.checkIsNullOrEmpty(tempGI))) {
            GI = new GlobalInput();
//            GI.Operator = "F53500406";
//            GI.Operator = "A50700111";
//            GI.Operator = "A51800724";
//            GI.Operator = "110001006";
//            GI.Operator = "330401261";
            GI.Operator = "851500039";
//            GI.ComCode = "A10";
//            GI.ComCode = "110";
//            GI.ComCode = "340";
            GI.ComCode = "850";
            GI.PwdErrCount = 0;
            GI.logoflag = true;
            GI.LastLogoTime = new Date().getTime();
            GI.chanlesign = "I"; //I个险 G经代  Y银保 WSM职场营销
            GI.riskSaleGroup = "000000";
//            GI.UserCode = "53500406";
//            GI.UserCode = "50700111";
//            GI.UserCode = "51800724";
//            GI.UserCode = "10001006";
            GI.UserCode = "51500039";
            GI.BuninessName = "淄博本部营业处００１";
            GI.BuninessNo = "ED001";
            GI.UserType = "3";
            GI.bankCode = "";
        } else {// 如果是正式环境，则返回session中存储值
            GI = (GlobalInput) request.getSession().getAttribute("GI");// (GlobalInput)
            if (CommonUtil.checkIsNullOrEmpty(GI)){
                logger.error("从session中获取GI为空");
            }
        }
        return GI;
    }
```





```
    /**
     * 获取人脸识别返回数据
     * 请求完整参数示例说明：{“APPID”:”WJ10021”,”user_id”:”jsakdiJh”,”recode”:”0”,”msg”:”成功”,”sim”:”90”,”valid_date”:”2013.12.30-2033.12.30”}
     * APPID：业务系统与本系统的关联标识
     * user_id：用户标识
     * recode：返回码（0为成功）
     * msg：返回信息（返回码非0时返回错误信息）
     * sim：相似度百分比
     * valid_date：证件有效期
     *
     * @param userId
     * @param recode
     * @param echostr
     * @param request
     */
    @RequestMapping("/faceRecognitionResults")
    public void getFaceRecognitionResults(@RequestParam("user_id") String userId,
                                          @RequestParam("recode") String recode,
                                          @RequestParam("echostr") String echostr,
                                          HttpServletRequest request) {
        logger.info("人脸识别返回参数：[user_id={},recode={},echostr={}]", userId,recode,echostr);
//        JSONObject data = JSONObject.parseObject(body);
//        String userId = data.getString("user_id");
//        String recode = data.getString("recode");
//        String echostr = data.getString("echostr");
        // 获取redis中的user_id 判断当前随机码是否相同
        String prtnum = redisManager.get(userId).toString();
        // 保存代理人至session
        if (CommonUtil.checkIsNullOrEmpty(prtnum)){
            HttpSession session = request.getSession();
            CommonServiceImpl commonService = new CommonServiceImpl();
            GlobalInput tempGI = commonService.queryNewGI(prtnum);
            session.setAttribute("GI", tempGI);
            logger.info("人脸识别回调函数代理人查询，当前单号--->{},当前代理人信息--->{}",prtnum,tempGI);
        }else{
            logger.error("人脸识别回调函数代理人查询，当前单号为空");
            return;
        }

        FormLSContExtDB formLSContExtDB = new FormLSContExtDB();
        formLSContExtDB.setPrtNum(prtnum);
        FormLSContExtSet formLSContExtSet = formLSContExtDB.query();
        // 数据库是否存在
        if (formLSContExtSet.size() > 0) {
            FormLSContExtSchema updateFormLSContExtSchema = formLSContExtSet.get(1);
            // TODO 此处数据库尚未创建字段，待数据库创建字段后取消注释
            if ("0".equals(recode)) {
                //updateFormLSContExtSchema.setFaceflag("通过");
            } else {
                //updateFormLSContExtSchema.setFaceflag("未通过");
            }
            formLSContExtDB.setSchema(updateFormLSContExtSchema);
            if (formLSContExtDB.insert()) {
                logger.info("人脸识别结果更新成功，prtnum={}", prtnum);
            }
        } else {
            // 保存人脸识别结果
            FormLSContExtSchema formLSContExtSchema = new FormLSContExtSchema();
            formLSContExtSchema.setPrtNum(prtnum);
            formLSContExtDB.setSchema(formLSContExtSchema);
            if (formLSContExtDB.insert()) {
                logger.info("人脸识别结果入库成功，prtnum={}", prtnum);
            }
        }
        // 保存证件照
        if ("0".equals(recode) && !CommonUtil.checkIsNullOrEmpty(prtnum)) {
            // 通过则保存人脸识别证件照
            FormMultDataSchema formMultDataSchema = new FormMultDataSchema();
            formMultDataSchema.setPrtNum(prtnum);
            // 拼接COS证件照地址
            String cosPath = "/face/" + userId + "_" + echostr + "_zheng.jpg";
            formMultDataSchema.setDataType("4");
            formMultDataSchema.setDataIndex(1);
            formMultDataSchema.setRemotePath(cosPath);
            formMultDataSchema.setMakeData(new Date());
            FormMultDataDB formMultDataDB = new FormMultDataDB();
            formMultDataDB.setPrtNum(prtnum);
            FormMultDataSet formMultDataSet = formMultDataDB.query();
            if (formMultDataSet.size() > 0) {
                FormMultDataSchema updateformMultDataSchema = formMultDataSet.get(1);
                updateformMultDataSchema.setRemotePath(cosPath);
                if (formMultDataDB.update()) {
                    logger.info("人脸识别身份证地址更新成功，prtnum={}", prtnum);
                }
            } else {
                formMultDataDB.setSchema(formMultDataSchema);
                if (formMultDataDB.insert()) {
                    logger.info("人脸识别身份证入库成功，prtnum={}", prtnum);
                }
            }
            
        }
    }
```

