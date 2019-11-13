#define MAX 10


char z[10]="-";

typedef struct {
	char y[10];
} itemtype;

typedef struct {
	int size;
	itemtype items[MAX];
} orderedlist;


void Insert(orderedlist *OL, itemtype item1, itemtype item2)
{
    int x, i;
    if(OL->size==0){
        OL->size+=2;
        strcpy(OL->items[0].y, item1.y);
        strcpy(OL->items[1].y, item2.y);
}
    else{
        OL->size+=2;
		for(i=OL->size-1;i>=0;i){
        strcpy(OL->items[i].y, OL->items[i-=2].y);
        }
		for(i=OL->size;i>=1;i){
        strcpy(OL->items[i].y, OL->items[i-=2].y);
        }
    }
        strcpy(OL->items[0].y, item1.y);
        strcpy(OL->items[1].y, item2.y);
return;
}



void createorderedlist(orderedlist *OL)
{
	int i;
	for (i=0;i<MAX;i++)
		strcpy(OL->items[i].y, z);
	OL->size=0;
	return;
}

int orderedlistlength(orderedlist *OL)
{
	int x;
	x=OL->size;
	return x;
}



void orderedlistdelete(orderedlist *OL, int Position)
{
	int f;
	if(Position>MAX)
		printf("\nCannot delete! Position is over the list limit");
	else
	{
		for(f=Position-1;f<MAX-1;f++)
		strcpy(OL->items[f].y, OL->items[f+1].y);
		strcpy(OL->items[MAX-1].y, z);
		OL->size--;
	}
	return;
}

void orderedlistdisplay(orderedlist *OL)
{
	int g;
	if (OL->size==0)
		printf("\n\nList Empty!\n");
	else if (OL->size<0)
		printf("\n\nCreate an empty ordered list first!\n");
	else
	{
	printf("\n\n");
		for(g=0;g<MAX;g++)
		printf("%s ", OL->items[g].y);
		printf("\n");
			}
	return;
}

	
void removeAll(orderedlist *OL)
{
	int f;
	{
		int y = MAX;
        for(f=0;f<=MAX;f++)
		{
        strcpy(OL->items[f].y, OL->items[f+1].y);
		strcpy(OL->items[f].y, z);
    }
		
	}
	OL->size==0;
	return;
}

void InsertTwo(orderedlist *pL, itemtype item1, itemtype item2)
{
	int i,x,comp;	

	{
		if(pL->size==0){
            pL->size++;
            strcpy(pL->items[0].y, item1.y);
            strcpy(pL->items[1].y, item2.y);
            return;
            }
        else{
        pL->size+=2;
        for(i=MAX-1;i>0;i--){
		strcpy(pL->items[i].y, pL->items[i-2].y);
		
            }
        for(i=MAX-2;i>1;i--){
		strcpy(pL->items[i].y, pL->items[i-1].y);

            }              
              
            }//end of secondary else
            strcpy(pL->items[0].y, item1.y);
            strcpy(pL->items[1].y, item2.y);
            pL->size+=2;
            }//end of main else
	return;
}

void orderedlistinsert(orderedlist *OL, int Position, itemtype NewItem)
{
	int i;	
	if(Position>MAX)
	{
		printf("\nThe position of the Item is over the list limit\n");
		
	}
	else
	{
		for(i=MAX-1;i>Position-1;i--)
			strcpy(OL->items[i].y, OL->items[i-1].y);
		strcpy(OL->items[Position-1].y, NewItem.y);
		OL->size++;
	}
	return;
}
