#include <fstream>
#include <iostream>
#include<string>
using namespace std;

void file_w()//д �����ӣ� 
{
   string data;
   string cmp="q!";
   // ��дģʽ���ļ�
   fstream outfile;
   outfile.open("afile.dat",ios::out|ios::app);
   
   cout << "д������  q: �����˳�   *��ʾ����Ϣ" << endl;
   do 
   {
   			cout << "����ѧ��ѧ��: "; 
			cin>>data;
			if(data=="q")
			{
				break;
			}
			else{
					outfile << data <<'|';
			}
			   // ���ļ�д���û����������
		
			cout << "����ѧ������: "; 
			cin >> data;
			   // �ٴ����ļ�д���û����������
			if(data=="q")
			{
				break;
			}
			else{
					outfile << data <<'|';
			}
			
			cout << "����ѧ���绰����: "; 
			cin >> data;
			   // �ٴ����ļ�д���û����������
			if(data=="q")
			{
				break;
			}
			else{
					outfile << data <<'|';
			}
			outfile <<endl;
   }while(data!="q");
   // �رմ򿪵��ļ�
   outfile.close();
}

int file_r()//�� 
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

void flie_replace_temp()//�޸���Ҫ�õ��Ļ����ļ� 
{
	ifstream file;
	fstream file_temp;
	file.open("tmp.dat",ios::in);
	file_temp.open("afile.dat",ios::out|ios::trunc);
	if(!file.is_open())
       return ;
       std::string strLine;
       /*ɸѡÿ�������зֱ���Ϣ*/
       
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

void flie_replace()//�޸� 
{
	string x;
	cout << "������q��ֹ����";
	cout << "������Ҫ�޸ĵ�ѧ��������ѧ��:";
	cin >> x;
	ifstream file;
	fstream file_temp;
	file.open("afile.dat",ios::in);
	file_temp.open("tmp.dat",ios::out|ios::trunc);
	/*��tmp.dat�ļ��ж������������ݣ�tmp.datΪ����������ļ�*/
	if(!file.is_open())
       return ;
       std::string strLine;
       /*ɸѡÿ�������зֱ���Ϣ*/
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
					cout<<"�����������޸ĺ��ѧ�� ���� �绰����"<<endl;
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

void flie_delete_temp()//ɾ������Ҫ�õ������ļ��� 
{
	ifstream file;
	fstream file_temp;
	file.open("tmp.dat",ios::in);
	file_temp.open("afile.dat",ios::out|ios::trunc);
	if(!file.is_open())
       return ;
       std::string strLine;
       /*ɸѡÿ�������зֱ���Ϣ*/
       
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

void flie_delete()//ɾ�� 
{
	string x;
	cout << "������q��ֹ����";
	cout << "������Ҫɾ����ѧ��������ѧ��:";
	cin >> x;
	ifstream file;
	fstream file_temp;
	file.open("afile.dat",ios::in);
	file_temp.open("tmp.dat",ios::out|ios::trunc);
	/*��tmp.dat�ļ��ж������������ݣ�tmp.datΪ����������ļ�*/
	if(!file.is_open())
       return ;
       std::string strLine;
       /*ɸѡÿ�������зֱ���Ϣ*/
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

void flie_search()//�� 
{
    string x;
    cout << "������q��ֹ����";
	cout << "������Ҫѧ��������ѧ�Ž��в���:";
	cin >> x;
	ifstream file;
	file.open("afile.dat",ios::in);
	if(!file.is_open())
       return ;
       std::string strLine;
       /*ɸѡÿ�������зֱ���Ϣ*/
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
				cout<<"����Ϊ��"<<str[1]<<'\t'<<"�绰����Ϊ�� "<<str[2]<<endl;
				flag=1;
			}
			else if(str[1]==x)
			{
				cout<<"����Ϊ��"<<str[0]<<'\t'<<"�绰����Ϊ�� "<<str[2]<<endl;
				flag=1;
				
			}      
       }
       	if(flag==0)
		{	
			cout<<"���޴��ˣ�"<<endl;
		}
       file.close();
}

int main ()
{
	char check;
	cout<<"������ w ��д || r���� || c����|| d:ɾ��|| e���� || q���˳���"<<endl;
	cout<<"r: �ļ�ȫ������ c������ѧ��/��������"<<endl;
	cin>>check;
	while(check!='q')
	{
		if(check=='w'){
			file_w();
			cout<<endl<<"������ w ��д || r���� || c����|| d:ɾ��|| e���� || q���˳���"<<endl;
			cout<<"r: �ļ�ȫ������ c������ѧ��/��������"<<endl;		
		}
		else if(check=='r'){
			file_r();	
			cout<<endl<<"������ w ��д || r���� || c����|| d:ɾ��|| e���� || q���˳���"<<endl;
			cout<<"r: �ļ�ȫ������ c������ѧ��/��������"<<endl;
		}
		else if(check=='c'){
			flie_search();	
			cout<<endl<<"������ w ��д || r���� || c����|| d:ɾ��|| e���� || q���˳���"<<endl;
			cout<<"r: �ļ�ȫ������ c������ѧ��/��������"<<endl;
		}
		else if(check=='d'){
			flie_delete();	
			cout<<endl<<"������ w ��д || r���� || c����|| d:ɾ��|| e���� || q���˳���"<<endl;
			cout<<"r: �ļ�ȫ������ c������ѧ��/��������"<<endl;
		}
		else if(check=='e'){
			flie_replace();	
			cout<<endl<<"������ w ��д || r���� || c����|| d:ɾ��|| e���� || q���˳���"<<endl;
			cout<<"r: �ļ�ȫ������ c������ѧ��/��������"<<endl;
		}
		else{
			cout<<"�����ʽ��������������"<<endl;
		} 
		cin>>check;
	}
    
   return 0;
}


