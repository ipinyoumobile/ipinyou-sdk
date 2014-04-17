##Pinyou 固定位广告Android SDK集成指南


### Android SDK集成流程

####1. 获取广告位ID
注册自己的App并获取广告位ID`AdUnit`

####2. 导入Android SDK jar包

* 在项目的根目录新建libs文件夹(可选)。
* 右键单击新建的libs文件夹,在弹出窗口中,选择Import -> General -> File System,完成操作 后,点击“Next”按钮,进入下一步。
* 找到Pinyou_Android_SDK/libs文件夹路径,右侧选中芒果SDK (Pinyou_SDK_Android.jar),选中Create selected folders only
* 选中libs文件夹中所有jar包,单击右键->Build Path->Add to Build Path


####3. 添加用户权限

``` xml
<!-- 添加用户权限 --><!-- 连接网络权限INTERNET ,用于请求广告(必须) --><uses-permission android:name="android.permission.INTERNET" /><!-- 读取手机基本信息权限READ_PHONE_STATE,用于精确统计用户的机型等信息(必须)--><uses-permission android:name="android.permission.READ_PHONE_STATE" /><!-- 读取网络信息权限ACCESS_NETWORK_STATE,用于识别gprs网络的接入点的情况(必须) --><uses-permission android:name="android.permission.ACCESS_NETWORK_STATE" /><!-- 获取用户地理信息权限,用于帮助精确统计开发者的程序发布之后的用户分布情况 --><uses-permission android:name="android.permission.ACCESS_FINE_LOCATION" /> 
<uses-permission android:name="android.permission.ACCESS_COARSE_LOCATION" /><uses-permission android:name="android.permission.ACCESS_LOCATION_EXTRA_COMMANDS" /><!--获得当前wifi的状态--> 
<uses-permission android:name="android.permission.ACCESS_WIFI_STATE" /><!--拨打电话权限 --><uses-permission android:name="android.permission.CALL_PHONE" /> ```

####4. 配置广告展示代码

#####4.1 在要展示广告的Activity的`OnCreate`方法放置以下代码

``` java
adView = new AdView(this, "hA.3Y");//不需要设置广告位尺寸,会根据屏幕自适应
//adView.noCloser = true;//显示关闭按钮
LinearLayout layout = (LinearLayout) findViewById(R.id.linearLayout);
layout.addView(adView,0);
adView.loadAd();
```

#####4.2 广告关闭按钮的回调方法
  
需要展示广告主的Activity实现AdsPinyouListener接口,并覆盖如下方法

``` java
	/* 广告关闭按钮回调方法
	 * return true关闭广告,false不关闭
	 */
	@Override
	public boolean onAdClosed(){
		logToast(this,"You can buy the pro edition to hide the Ad!!");
		return false;
	}
``` 

#####4.3 释放资源
开发者需要在启动的第一个Activity的onDestroy方法中调

``` java
/** Called before the activity is destroyed. **/
  	@Override
  	public void onDestroy() {
    		// Destroy the AdView.
		if (adView != null) {
    			adView.destroy();
    		}
    		super.onDestroy();
  	}
```



###联系品友**如果您有任何问题或疑问,请及时联系品友移动组。我们将在第一时间做出回应。**** Email:mobile-core@ipinyou.com **