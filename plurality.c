#include <string.h>
#include <stdio.h>
#include <cs50.h>

#define MAX 9

typedef struct
{
    string name;
    int votes;
}
candidate;

candidate pool[MAX];
int num_of_candidates;

bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    if (argc <= 1)
    {
        printf("Error 57#r..! No candidates inserted\n");
        return 1;
    }
    
    else if (argc == 2)
    {
        printf("Error NK1953...One candidate is not democratic...BOOOO!!\n");
        return 1;
    }
    
    else if (argc > 10)
    {
        printf("Constituency Confusion...Too many candidates\n");
        return 1;
    }
    
    num_of_candidates = argc - 1;
    
    for (int z = 0; z < num_of_candidates; z++) //initializing the votes 
    {
        pool[z].votes = 0;
    }
    
    for (int l = 0; l < num_of_candidates; l++)
    {
        pool[l].name = argv[l + 1]; //assigning appropriate names from command line
    }
    
    int num_of_voters = get_int("How many people are voting?\n");
    
    string ballot[num_of_voters];
    
    for (int k = 0; k < num_of_voters; k++)
    {
        ballot[k] = get_string("Please vote: \n");
        
        bool shnik = vote(ballot[k]); // calling the vote function
        
        if (shnik == false)
        {
            printf("INVALID VOTE\n");
        }
        
    }
    
    print_winner();
    
    return 0;
}

bool vote(string name)
{   
    for (int b = 0; b < num_of_candidates; b++)
    {
        if (strcmp(name, pool[b].name) == 0)
        {
            pool[b].votes++;
            return true;
        }
    }
    
    return false;
}

void print_winner(void)
{
    int largest = pool[0].votes; //printing the name of the winner
    int index = 0;
    
    for (int i = 0; i < num_of_candidates; i++)
    {
        if (largest < pool[i].votes)
        {
            largest = pool[i].votes;
            index = i;
        }
    }
        
    printf("%s won", pool[index].name); 
    printf("\n");
    
    int index1 = 0;      //the case when there are two winner
     
    for (int j = 0; j < num_of_candidates; j++)
    {
       if ((pool[j].votes == largest) && (pool[j].name != pool[index].name))   
       {
            largest = pool[j].votes;
            index1 = j;
            printf("%s won\n", pool[index1].name);
       }
    }
}
