#include <stdio.h>
#include <string.h>

#define isleap(y)	((y) % 4 == 0 && ((y) % 100 != 0 || (y) % 400 == 0))

int main(){
    int sunday_count = 0;
    const char* days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int index = 0;
    for (int i = 1900; i < 2000; ++i){
        if (isleap(i))
            for (int k = 1; k <= 365; ++k){
                if (k == 1 && !strcmp(days[index], "Sunday")) //January 1st
                    ++sunday_count;
                else if (k == 32 && !strcmp(days[index], "Sunday")) //February 1st
                    ++sunday_count;
                else if (k == 61 && !strcmp(days[index], "Sunday")) //March 1st
                    ++sunday_count;
                else if (k == 92 && !strcmp(days[index], "Sunday")) //April 1st
                    ++sunday_count;
                else if (k == 122 && !strcmp(days[index], "Sunday")) //May 1st
                    ++sunday_count; 
                else if (k == 153 && !strcmp(days[index], "Sunday")) //June 1st
                    ++sunday_count;
                else if (k == 183 && !strcmp(days[index], "Sunday")) //July 1st
                    ++sunday_count;
                else if (k == 214 && !strcmp(days[index], "Sunday")) //August 1st
                    ++sunday_count;
                else if (k == 245 && !strcmp(days[index], "Sunday")) //September 1st
                    ++sunday_count;
                else if (k == 275 && !strcmp(days[index], "Sunday")) //October 1st
                    ++sunday_count;
                else if (k == 306 && !strcmp(days[index], "Sunday")) //November 1st
                    ++sunday_count;
                else if (k == 336 && !strcmp(days[index], "Sunday")) //December 1st
                    ++sunday_count;
                ++index;
                if (index == 7)
                    index = 0;                                 
            }
        
        else 
            for (int k = 1; k <= 365; ++k){
                if (k == 1 && !strcmp(days[index], "Sunday")) //January 1st
                    ++sunday_count;
                else if (k == 32 && !strcmp(days[index], "Sunday")) //February 1st
                    ++sunday_count;
                else if (k == 60 && !strcmp(days[index], "Sunday")) //March 1st
                    ++sunday_count;
                else if (k == 91 && !strcmp(days[index], "Sunday")) //April 1st
                    ++sunday_count;
                else if (k == 121 && !strcmp(days[index], "Sunday")) //May 1st
                    ++sunday_count; 
                else if (k == 152 && !strcmp(days[index], "Sunday")) //June 1st
                    ++sunday_count;
                else if (k == 182 && !strcmp(days[index], "Sunday")) //July 1st
                    ++sunday_count;
                else if (k == 213 && !strcmp(days[index], "Sunday")) //August 1st
                    ++sunday_count;
                else if (k == 244 && !strcmp(days[index], "Sunday")) //September 1st
                    ++sunday_count;
                else if (k == 274 && !strcmp(days[index], "Sunday")) //October 1st
                    ++sunday_count;
                else if (k == 305 && !strcmp(days[index], "Sunday")) //November 1st
                    ++sunday_count;
                else if (k == 335 && !strcmp(days[index], "Sunday")) //December 1st
                    ++sunday_count;
                ++index;
                if (index == 7)
                    index = 0;                                 
            }
        
    }
    printf("Sunday number 1st of the month:%d\n", sunday_count);
    return 0;
}
