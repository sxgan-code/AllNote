# 一、java日期格式工具类

```java
public class MyDateUtil {
    /**
     * 获取当前日期的字符串形式，YYYY年MM月dd日 HH:mm:ss
     * @return
     */
    public static String getDateString(){
        Date date = new Date();
        SimpleDateFormat sf = new SimpleDateFormat("yyyy年MM月dd日 HH:mm:ss");
        String strDate = sf.format(date);
        return strDate;
    }
    /**
     * 转换日期格式为字符串，yyyy年MM月dd日 HH:mm:ss
     * @param date
     * @return
     */
    public static String formatDateToString(Date date){
        SimpleDateFormat sf = new SimpleDateFormat("yyyy年MM月dd日 HH:mm:ss");
        String strDate = sf.format(date);
        return strDate;
    }
    /**
     * 转换字符串格式为日期，输入格式为：yyyy/MM/dd HH:mm:ss
     * @param dateString
     * @return
     */
    public static Date formatStringToDate(String dateString){
        SimpleDateFormat sf = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
        Date date = null;
        try {
            date = sf.parse(dateString);
        } catch (ParseException e) {
            e.printStackTrace();
        }
        return date;
    }
}

```

