#include<iostream>
#include<string.h>
#include<stdio.h>
using  namespace std;
int main(){
	char gram[50];
	int i,j=0,pos1=0,pomax=20;
	cout<<"Enter Production:";
	scanf("%s",gram);
	int count=0;
	int point[50];
	char fp[50];		
	for(i=0;gram[i]!='\0';++i){
		if(gram[i]=='|')
			point[count++]=i;
		else
			if(i>2)
				if(count==0){
					fp[i-3]=gram[i];
					pomax=i-2;
				}else{
					int l=i-point[count-1]-1;
					if(pomax>l&&fp[l]==gram[i]){
						//cout<<fp<<"  gram:"<<gram<<"   i:"<<i<<endl;
					}else{
						fp[l]='\0';
						pomax=l+1;
						//cout<<fp<<"    L:"<<l<<"   pomax:"<<pomax<<endl;
					}		
				}
		}
	if(count==0)
		cout<<"Not in left recurrsion factoring form";
	else
	{
		pomax=strlen(fp);
		cout<<gram[0]<<"->"<<fp;
		if(pomax>0){
		pos1=0;
		
		point[count]=strlen(gram);
		for(i=3+pomax;i<point[0];++i)
			fp[pos1++]=gram[i];
		for(i=1;i<=count;++i){
			fp[pos1++]='|';
			for(j=point[i-1]+pomax+1;j<point[i];++j)
			fp[pos1++]=gram[j];	
		}
		fp[pos1++]='\0';
		cout<<gram[0]<<"\'"<<endl<<gram[0]<<"\'->"<<fp;		
	}else{
		cout<<"Not in left recurrsion factoring form >"<<endl<<fp<<endl;
	}
	}
return 0;
}
