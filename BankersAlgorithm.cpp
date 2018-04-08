#include <iostream>
#include <fstream>

using namespace std;

bool isLessThan(int ara1[],int ara2[],int size)
{
    for (int i = 0; i < size ; ++i)
    {
        //cout<<"need: "<<ara1[i]<<"ara2: "<<ara2[i]<<endl;
        if(ara1[i]>ara2[i])
            return false;
    }
    return true;
}

void add(int ara1[],int ara2[],int size)
{
    for (int i = 0; i < size ; ++i)
    {
        ara1[i]=ara1[i]+ara2[i];
    }
}

bool isFinished(bool ara[],int size)
{
    for (int i = 0; i < size ; ++i)
    {
        if(ara[i]== false)
            return false;
    }
    return true;
}

int main()
{
    ifstream fin("in2.txt");
	
    cout << "Banker's Algorithm" << endl;
	if(!fin.is_open())
	{
		cout<<"Input file not found"<<endl;
		return 0;
	}

    int numberOfProcesses,numberOfResType;

    if(fin.is_open())
    {
        cout<<"file Opened"<<endl;
    }
    else
    {
        cout<<"unable to open file"<<endl;
        return 0;
    }
    //cin>>numberOfProcesses>>numberOfResType;
    fin>>numberOfProcesses>>numberOfResType;
    cout<<"Number of Processes: "<<numberOfProcesses<<" Number of Resource Types: "<<numberOfResType<<endl;

    bool finished[numberOfProcesses];

    for (int k = 0; k < numberOfProcesses ; ++k)
    {
        finished[k]= false;
    }

    int availableRes[numberOfResType];

    for (int i = 0; i < numberOfResType ; ++i)
    {
        //cin>>availableRes[i];
        fin>>availableRes[i];
        cout<<availableRes[i]<<" ";
    }
    cout<<endl;

    //Allocation Array input
    int currentAlocation[numberOfProcesses][numberOfResType];

    for (int i = 0; i < numberOfProcesses; ++i)
    {
        for (int j = 0; j < numberOfResType ; ++j)
        {
            //cin>>currentAlocation[i][j];
            fin>>currentAlocation[i][j];
            cout<<currentAlocation[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Need Array Input"<<endl;
    //need array input
    int toBeAllocated[numberOfProcesses][numberOfResType];

    for (int i = 0; i < numberOfProcesses; ++i)
    {
        for (int j = 0; j < numberOfResType ; ++j)
        {
            //cin>>toBeAllocated[i][j];
            fin>>toBeAllocated[i][j];
            cout<<toBeAllocated[i][j]<<" ";
        }
        cout<<endl;
    }

    bool safe;

    int x=0;

    while (x<numberOfProcesses)
    {
        safe= false;
        for (int i = 0; i < numberOfProcesses ; ++i)
        {
            if(finished[i]== false && isLessThan(toBeAllocated[i],availableRes,numberOfResType))
            {
                finished[i]= true;
                add(availableRes,currentAlocation[i],numberOfResType);
                safe= true;
                x++;
            }
        }
        if(!isFinished(finished,numberOfProcesses))
        {
            cout<<"UnSafe"<<endl;
            return 0;
        }

    }
    cout<<"safe"<<endl;

    return 0;
}
