#include<stdio.h>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
string str[1000];
int flag1[300],flag2[300];
int check(string str1,string str2)
{
    int i,j;
    int ok;
    //cout<<str1<<"  "<<str2<<endl;
    for(i=0;i<300;i++) flag1[i]=flag2[i]=0;   
    for(j=0;j<300;j++) flag1[i]=0;
    for(j=0;j<str1.size();j++) flag1[str1[j]]=1;
    ok=0;
    for(i=0;i<str2.size();i++){
        ok=0;
        for(j=i;j<str2.size()&&str2[j]>='a'&&str2[j]<='z';j++){
            if(flag1[str2[j]]) {
             //   cout<<str2[j]<<endl;
                ok=1;
            }
        }
      // cout<<ok<<endl;
        if(ok==0) goto line;
        while(j<str2.size()&&str2[j]!='|'){
            if(str2[j]=='+'){
                if(flag1[str2[j+1]]==0) goto line;
            }
            else {
                if(flag1[str2[j+1]]==1) goto line;
            }
            j+=2;
        }
        return 1;
        line:
        for(;i<str2.size();i++){
            if(str2[i]=='|') break;
        }
    }
    return 0;
}
int main()
{
	int i,j;
	string tp1="elk",tp2="acm+e";
//	cout<<check(tp1,tp2)<<endl;
	while(1)
	{
		cin>>str[0];
		if(str[0]=="#") break;
		i=1;
		while(cin>>str[i++])
		{
            if(str[i-1]=="*") break;
        }
        i--;
        sort(str,str+i);
        str[i]="NONE";
        string str2;
    //   for(j=0;j<=i;j++) cout<<str[j]<<endl;
        while(cin>>str2)
        {
            if(str2=="**") break;
            for(j=0;j<i;j++){
                if(check(str[j],str2)) break;
            }
            cout<<str[j]<<endl;
        }
        cout<<"$"<<endl;
	}
	return 0;
}

