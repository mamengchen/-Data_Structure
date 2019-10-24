import jqdatasdk
import os
import pandas as pd
jqdatasdk.auth("17729157828","MMCmmc623")
data_start = []
data_end = []
for data_str in range(2017, 2018):
	data_start.append(str(date_str)+"-01-01")
	data_end.append(str(date_str)+"-12-31")

def file_name(file_dir):
	L = []
	for root, dirs, files in os.walk(file_dir):
		for file in files:
			if os.path.splitext(file)[1]=='.csv':
				L.append(file.split(".")[0])
	return L
	
if __name__ == '__main__':
	feature_index = pd.read_excel("所有期货合约.xlsx")
	index_1 = list(feature_index["index1"])
	name_1 = list(feature_index["name"])
	c_name = list(feature_index["display_name"])
	
	for d in range(len(date_start)-1):
		try:
			os.makedirs("期货1分钟数据/" + date_start[d].split("-")[0])
		except:
			pass
		new_index1 = feature_index[feature_index["is_"+date_start[d].split("-")[0]]==1]
		print(len(new_index1))
		already_index = file_name("期货1分钟数据/"+date_start[d].split("-")[0])
		new_index = list(set(list(new_index1["name"]))-set(already_index))
		print(len(new_index))
		for i in new_index:
			sub = feature_index[feature_index["name"]==i]
			df = jqdatasdk.get_price(security = list(sub["index1"])[0],  start_date=date_start[d],end_date=date_start[d+1], frequency='1m', fields=['open', 'close', 'high', 'low', 'volume', 'money'],skip_paused=True)
			if len(df)>0:
				df["name"] = list(sub["name"])[0]
				df["time"] = df.index
				df = df.loc[:,["name","time",'open', 'close', 'high', 'low', 'volume', 'money']]
				df.to_csv("期货1分钟数据/"+date_start[d].split("-")[0]+"/"+list(sub["name"])[0]+".csv",index=False)