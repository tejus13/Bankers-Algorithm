#include<bits/stdc++.h>

using namespace std;

int times=0;
vector<int> grant;
set< pair<int, int> > s;

int pro,res,que;

int avail[100];//availabe resource
vector<int>id;
vector<int>arr_time[100];
int maxi[100][100];
int alloc[100][100];
int need[100][100];
int m=0;

void fun()
{

    for(int i=0; i<arr_time[times].size(); i++)
    {
        s.insert({arr_time[times][i],0});
    }
    //cout<<s.size()<<endl;
}
int main()
{
	memset(arr_time,0,sizeof(int)*100);

    cin>>pro>>res>>que;
    for(int i=0; i<pro; i++)
    {
        int a;
        cin>>a;
        id.push_back(a);

    }
    for(int i=0; i<pro; i++)
    {
        int a;
        cin>>a;
        if(a>m)
        	m=a;
        arr_time[a].push_back(id[i]);
    }
    for(int i=0; i<res; i++)
    {
        cin>>avail[i];
    }
    for(int i=0; i<que; i++)
    {
    	int x=id[i];
        for(int j=0; j<res; j++)
        {
            cin>>maxi[x][j];
        }
    }
    for(int i=0; i<pro; i++)
    {	int x=id[i];
        for(int j=0; j<res; j++)
        {
            cin>>alloc[x][j];
        }
    }
    for(int i=0; i<que; i++)
    {
    	//int x=id[i];
    	int a;
        for(int j=0; j<=res; j++)
        {
        	int b;
        	cin>>b;
        	if(j==0)
        		a=b;
        	if(j>0)
        	need[id[a]][j-1]=b;
        }
    }
    /****************input taken***************/
    for(int i=0; i<10000; i++)
    {
        if(arr_time[i].size()>0)
        {
            times=i;
            break;
        }
    }
    fun();
    set< pair<int,int> > :: iterator it=s.begin();

    int r;

    for(it; it!=s.end();)
    {
        if(it->second==2)
          {  it++;
          	 if(it==s.end())
                    {
                    	times++;
                    	if(times<=m)
                    	{fun();
                    	it=s.begin();
                    }
                }

          }
          
        else if(it->second==0)
        {
        	int x=it->first;
            for( r=0; r<res;)
            {
                if((need[x][r])>avail[r])
                {
                    cout<<"Deny"<<endl;
                    //it++;
                    
                    s.erase({x,0});
                    s.erase({x,1});
                    s.erase({x,2});
                    s.insert({x,1});
                    it++;
                    if(it==s.end())
                    {
                    	times++;
                    	if(times<=m)
                    	{fun();
                    	it=s.begin();
                    }
                    }
                    break;
                }
                else
                    r++;
            }
            if(r==res)
            {
            	
                cout<<"Grant "<<endl;
                for(int i=0; i<r; i++)
                {
                    avail[i]+=alloc[x][i];
                }
               
                grant.push_back(it->first);
            
                s.erase({x,0});
                s.erase({x,1});
                s.erase({x,2});
                s.insert({x,2});
                times++;
                    	if(times<=m)
                    	{fun();
                    	it=s.begin();
                    }
                it=s.begin();
            }
        }
        else if(it->second==1)
        {
        	int b=0;
        	 int x=it->first;
      
            for( b=0; b<res;)
            {
                if((need[x][b])>avail[b])
                {  
                    cout<<"Deny "<<endl;
                    //it++;
                   
                    s.erase({x,0});
                    s.erase({x,1});
                    s.erase({x,2});
                    s.insert({x,1});
                    it++;
                    if(it==s.end())
                    {
                    	times++;
                    	if(times<=m)
                    	{fun();
                    	it=s.begin();
                    }
                    }

                    break;
                }
                else
                    b=b+1;
            }
            if(b==res)
            {
               
                s.erase({x,0});
                s.erase({x,1});
                s.erase({x,2});
                s.insert({x,0});
            }
        }
    }
    for(int i=0; i<grant.size(); i++)
    {
        cout<<grant[i]<<" ";
    }

    return 0;
}

