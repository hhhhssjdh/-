#include <fstream>
#include <iostream>
#include<string>
using namespace std;

void file_w()//写 （增加） 
{
   string data;
   string cmp="q!";
   // 以写模式打开文件
   fstream outfile;
   outfile.open("afile.dat",ios::out|ios::app);
   
   cout << "写入数据  q: 保存退出   *表示无信息" << endl;
   do 
   {
   			cout << "输入学生学号: "; 
			cin>>data;
			if(data=="q")
			{
				break;
			}
			else{
					outfile << data <<'|';
			}
			   // 向文件写入用户输入的数据
		
			cout << "输入学生姓名: "; 
			cin >> data;
			   // 再次向文件写入用户输入的数据
			if(data=="q")
			{
				break;
			}
			else{
					outfile << data <<'|';
			}
			
			cout << "输入学生电话号码: "; 
			cin >> data;
			   // 再次向文件写入用户输入的数据
			if(data=="q")
			{
				break;
			}
			else{
					outfile << data <<'|';
			}
			outfile <<endl;
   }while(data!="q");
   // 关闭打开的文件
   outfile.close();
}

int file_r()//读 
{
 
  ifstream file;
  file.open("afile.dat",ios::in);
  if(!file.is_open())
       return 0;
       std::string strLine;
       while(getline(file,strLine))
       {
            if(strLine.empty())
                continue;
            cout<<strLine <<endl;  
     }
     file.close();
}

void flie_replace_temp()//修改需要用到的缓存文件 
{
	ifstream file;
	fstream file_temp;
	file.open("tmp.dat",ios::in);
	file_temp.open("afile.dat",ios::out|ios::trunc);
	if(!file.is_open())
       return ;
       std::string strLine;
       /*筛选每行中三列分别信息*/
       
       while(getline(file,strLine))
       {
       	
            if(strLine.empty())
                continue; 
			char str[3][30];
            int pos=0;
            int j=0;
            for(int i=0;i<strLine.length();i++)
            {
            	if(strLine[i]!='|')
            	{
            		str[pos][j]=strLine[i];
            		j++;
				}
				else{
					str[pos][j]='\0';
					pos++;
					j=0;
				}
			}
			
			for(int i=0;i<3;i++)
			{
					file_temp << str[i] <<'|';
			}  
			file_temp <<endl;                 
       }
	  file.close();
      file_temp.close();
}

void flie_replace()//修改 
{
	string x;
	cout << "（输入q终止程序）";
	cout << "请输入要修改的学生姓名或学号:";
	cin >> x;
	ifstream file;
	fstream file_temp;
	file.open("afile.dat",ios::in);
	file_temp.open("tmp.dat",ios::out|ios::trunc);
	/*向tmp.dat文件中读入待处理的数据，tmp.dat为缓存的扇区文件*/
	if(!file.is_open())
       return ;
       std::string strLine;
       /*筛选每行中三列分别信息*/
       bool flag=0;
       while(getline(file,strLine))
       {
            if(strLine.empty())
                continue; 
			char str[3][30];
            int pos=0;
            int j=0;
            for(int i=0;i<strLine.length();i++)
            {
            	if(strLine[i]!='|')
            	{
            		str[pos][j]=strLine[i];
            		j++;
				}
				else{
					str[pos][j]='\0';
					pos++;
					j=0;
				}
			}
			for(int i=0;i<3;i++)
			{
				if((x==str[0]||x==str[1])&&flag==0)
				{
					cout<<"请依次输入修改后的学号 姓名 电话号码"<<endl;
					string data1;
					string data2;
					string data3;	
					cin>>data1;
					cin.ignore();
					file_temp << data1 <<'|';
					cin>>data2;
					cin.ignore();
					file_temp << data2 <<'|';
					cin>>data3;
					cin.ignore();
					file_temp << data3 <<'|'<<endl;
					flag=1;
				}
				else{
					if((x!=str[0]&&x!=str[1]))
					  file_temp << str[i] <<'|';
				}
			}  
			file_temp <<endl;              
       }
       file.close();
       file_temp.close();
       flie_replace_temp();
}

void flie_delete_temp()//删除（需要用到缓存文件） 
{
	ifstream file;
	fstream file_temp;
	file.open("tmp.dat",ios::in);
	file_temp.open("afile.dat",ios::out|ios::trunc);
	if(!file.is_open())
       return ;
       std::string strLine;
       /*筛选每行中三列分别信息*/
       
       while(getline(file,strLine))
       {
       	
            if(strLine.empty())
                continue; 
			char str[3][30];
            int pos=0;
            int j=0;
            for(int i=0;i<strLine.length();i++)
            {
            	if(strLine[i]!='|')
            	{
            		str[pos][j]=strLine[i];
            		j++;
				}
				else{
					str[pos][j]='\0';
					pos++;
					j=0;
				}
			}
			
			for(int i=0;i<3;i++)
			{
					file_temp << str[i] <<'|';
					//cout<<str[i];
			}  
			file_temp <<endl;                 
       }
	  file.close();
      file_temp.close();
}

void flie_delete()//删除 
{
	string x;
	cout << "（输入q终止程序）";
	cout << "请输入要删除的学生姓名或学号:";
	cin >> x;
	ifstream file;
	fstream file_temp;
	file.open("afile.dat",ios::in);
	file_temp.open("tmp.dat",ios::out|ios::trunc);
	/*向tmp.dat文件中读入待处理的数据，tmp.dat为缓存的扇区文件*/
	if(!file.is_open())
       return ;
       std::string strLine;
       /*筛选每行中三列分别信息*/
       while(getline(file,strLine))
       {
       	
            if(strLine.empty())
                continue; 
			char str[3][30];
            int pos=0;
            int j=0;
            for(int i=0;i<strLine.length();i++)
            {
            	if(strLine[i]!='|')
            	{
            		str[pos][j]=strLine[i];
            		j++;
				}
				else{
					str[pos][j]='\0';
					pos++;
					j=0;
				}
			}
			
			for(int i=0;i<3;i++)
			{
				if(x==str[0]||x==str[1])
				{
					
				}
				else{
					file_temp << str[i] <<'|';
				}
			}  
			file_temp <<endl;              
       }
       file.close();
       file_temp.close();
       flie_delete_temp();
}

void flie_search()//查 
{
    string x;
    cout << "（输入q终止程序）";
	cout << "请输入要学生姓名或学号进行查找:";
	cin >> x;
	ifstream file;
	file.open("afile.dat",ios::in);
	if(!file.is_open())
       return ;
       std::string strLine;
       /*筛选每行中三列分别信息*/
       bool flag=0;
       while(getline(file,strLine))
       {
       	
            if(strLine.empty())
                continue; 
			char str[3][30];
            int pos=0;
            int j=0;
            for(int i=0;i<strLine.length();i++)
            {
            	if(strLine[i]!='|')
            	{
            		str[pos][j]=strLine[i];
            		j++;
				}
				else{
					str[pos][j]='\0';
					pos++;
					j=0;
				}
			}
			
			if(str[0]==x)
			{
				cout<<"姓名为："<<str[1]<<'\t'<<"电话号码为： "<<str[2]<<endl;
				flag=1;
			}
			else if(str[1]==x)
			{
				cout<<"姓名为："<<str[0]<<'\t'<<"电话号码为： "<<str[2]<<endl;
				flag=1;
				
			}      
       }
       	if(flag==0)
		{	
			cout<<"查无此人！"<<endl;
		}
       file.close();
}

int main ()
{
	char check;
	cout<<"请输入 w ：写 || r：读 || c：查|| d:删除|| e：改 || q：退出！"<<endl;
	cout<<"r: 文件全部查找 c：根据学号/姓名查找"<<endl;
	cin>>check;
	while(check!='q')
	{
		if(check=='w'){
			file_w();
			cout<<endl<<"请输入 w ：写 || r：读 || c：查|| d:删除|| e：改 || q：退出！"<<endl;
			cout<<"r: 文件全部查找 c：根据学号/姓名查找"<<endl;		
		}
		else if(check=='r'){
			file_r();	
			cout<<endl<<"请输入 w ：写 || r：读 || c：查|| d:删除|| e：改 || q：退出！"<<endl;
			cout<<"r: 文件全部查找 c：根据学号/姓名查找"<<endl;
		}
		else if(check=='c'){
			flie_search();	
			cout<<endl<<"请输入 w ：写 || r：读 || c：查|| d:删除|| e：改 || q：退出！"<<endl;
			cout<<"r: 文件全部查找 c：根据学号/姓名查找"<<endl;
		}
		else if(check=='d'){
			flie_delete();	
			cout<<endl<<"请输入 w ：写 || r：读 || c：查|| d:删除|| e：改 || q：退出！"<<endl;
			cout<<"r: 文件全部查找 c：根据学号/姓名查找"<<endl;
		}
		else if(check=='e'){
			flie_replace();	
			cout<<endl<<"请输入 w ：写 || r：读 || c：查|| d:删除|| e：改 || q：退出！"<<endl;
			cout<<"r: 文件全部查找 c：根据学号/姓名查找"<<endl;
		}
		else{
			cout<<"输入格式错误，请重新输入"<<endl;
		} 
		cin>>check;
	}
    
   return 0;
}


