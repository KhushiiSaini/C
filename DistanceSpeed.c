#include <stdio.h>

int main(void)
{
    int num_laps;
    float dis_lap;
    float speed_lap;
    float Time;
    float total_distance;
    float total_time = 0;
    float avg_speed;
    int i;
    
    printf ("Enter the number of laps : " );
    scanf ("%d", &num_laps);
    if (num_laps <= 0){while (num_laps <= 0){
        printf("The value of number of laps must be positive and non zero\n");
        printf ("Enter the number of laps : ");
        scanf ("%d", &num_laps);}
    }
    
    printf ("Enter the distance of the lap : " );
    scanf ("%f", &dis_lap);
    if (dis_lap <= 0){ while (dis_lap <= 0){
        printf("The value of distance must be positive and non zero\n");
        printf ("Enter the distance of the lap : ");
        scanf ("%f", &dis_lap);}
    }
    
    printf("%-10s %-20s %-20s %-20s \n", "# of laps", "Distance", "Speed", "Time");
    printf("********************************************************** \n");
    for (i=1; i < num_laps + 1; ++i)
    {  
        printf("Enter the speed of the car during lap %d : ", i);
        scanf ("%f", &speed_lap);
        if (speed_lap <= 0) { while (speed_lap <= 0){
        printf("The value of speed must be positive and non zero\n");
        printf("Enter the speed of the car during lap %d : ", i);
        scanf ("%f", &speed_lap);}
    }
        Time = dis_lap/speed_lap ;
        total_time += Time;
        printf("%-10d %-20.2f %-20.2f %-20.2f \n", i, dis_lap, speed_lap,Time);
    }
    total_distance = (float)dis_lap * (float)num_laps ;
    avg_speed = (float) total_distance/(float)total_time ;
    printf("%-10s %-20.2f %-20.2f %-20.2f \n", "Total:", total_distance, avg_speed, total_time);
    
    return 0;
}

