#include <stdio.h>
#include <stdlib.h>

// Enum to represent the guests
typedef enum {
    AlanTuring,
    AdaLovelace,
    NielsBohr,
    MarieCurie,
    Socrates,
    Pythagoras,
    IsaacNewton
} Guest;

// Struct to represent the schedule
typedef struct {
    Guest timeSlots[4]; // Array of guests assigned to time slots
} Schedule;

// Function to check if a guest can be assigned to a specific time slot in the given schedule
int isGuestCompatible(Schedule schedule, Guest guest, int timeSlot)
{
    // 2) The PHY students want to see the physicists: Bohr (B), Curie (C), Newton (N).
    if ((guest == NielsBohr || guest == MarieCurie || guest == IsaacNewton) && schedule.timeSlots[timeSlot] != -1) {
        return 0;
    }
    // 3) The MATH students wants to see the mathematicians: Lovelace (L), Pythagoras (P), and Newton (N).
    if ((guest == AdaLovelace || guest == Pythagoras || guest == IsaacNewton) && schedule.timeSlots[timeSlot] != -1) {
        return 0;
    }
    // 4) The AI students wants to see the philosophers: Socrates (S), Pythagoras (P).
    if ((guest == Socrates || guest == Pythagoras) && schedule.timeSlots[timeSlot] != -1) {
        return 0;
    }
    // 5) The Society of Women Engineers want to see female speakers: Lovelace (L), Marie Curie (C).
    if ((guest == AdaLovelace || guest == MarieCurie) && schedule.timeSlots[timeSlot] != -1) {
        return 0;
    }
    // 6) The Aerospace club student want to see: Turing (T), Lovelace (L), and Newton (N)
    if ((guest == AlanTuring || guest == AdaLovelace || guest == IsaacNewton) && schedule.timeSlots[timeSlot] != -1) {
        return 0;
    }
    // 7) Finally, you want to take this opportunity and make your dream comes true.
    // In this matter, you will be happy if and only if you get to see both Curie (C) and Pythagoras (P).
    if (guest == MarieCurie && schedule.timeSlots[timeSlot] != -1) {
        return 0;
    }
    if (guest == Pythagoras && schedule.timeSlots[timeSlot] != -1) {
        return 0;
    }

    return 1;
}

int pureBacktrackingSearch(Schedule *schedule, int guestIndex)
{
    //printf("Pure backtracking search algorithm selected.\n");

    if (guestIndex >= 7)
        return 1; // All guests assigned, solution found

    for (int i = 0; i < 4; i++)
    {
        if (schedule->timeSlots[i] == -1 && isGuestCompatible(*schedule, guestIndex, i))
        {
            schedule->timeSlots[i] = guestIndex;

            if (pureBacktrackingSearch(schedule, guestIndex + 1))
                return 1; // Solution found


            // Backtrack if solution not found
            schedule->timeSlots[i] = -1;
        }
    }

    return 0; // No solution found

}

void backtrackingSearchForwardChecking() {
    printf("Backtracking search algorithm + forward checking selected.\n");
    // Add your code for backtracking search algorithm + forward checking here
}

void backtrackingSearchArcConsistency() {
    printf("Backtracking search algorithm + Arc Consistency selected.\n");
    // Add your code for backtracking search algorithm + Arc Consistency here
}

void backtrackingSearchDegreeHeuristic() {
    printf("Backtracking search algorithm + Degree Heuristic selected.\n");
    // Add your code for backtracking search algorithm + Degree Heuristic here
}

void backtrackingSearchMRV() {
    printf("Backtracking search algorithm + MRV selected.\n");
    // Add your code for backtracking search algorithm + MRV here
}

void backtrackingSearchMinConflict() {
    printf("Backtracking search algorithm + Min-Conflict selected.\n");
    // Add your code for backtracking search algorithm + Min-Conflict here
}

void printSchedule(Schedule *schedule, int isSolved)
{
    if (isSolved)
    {
        // Print the schedule
        printf("Schedule:\n");
        for (int i = 0; i < 4; i++) {
            printf("%d AM - %d AM: ", i + 10, i + 11);
            switch (schedule->timeSlots[i]) {
                case AlanTuring:
                    printf("Alan Turing\n");
                    break;
                case AdaLovelace:
                    printf("Ada Lovelace\n");
                    break;
                case NielsBohr:
                    printf("Niels Bohr\n");
                    break;
                case MarieCurie:
                    printf("Marie Curie\n");
                    break;
                case Socrates:
                    printf("Socrates\n");
                    break;
                case Pythagoras:
                    printf("Pythagoras\n");
                    break;
                case IsaacNewton:
                    printf("Isaac Newton\n");
                    break;
            }
        }
    }
    else
        printf("No valid schedule found.\n");

}

int main()
{
    int choice;

    do {

    Guest guests[] = {
            AlanTuring,
            AdaLovelace,
            NielsBohr,
            MarieCurie,
            Socrates,
            Pythagoras,
            IsaacNewton
    };
    int numGuests = 7;

    // Define the schedule
    Schedule *schedule = (Schedule *) malloc(sizeof(Schedule));
    for (int i = 0; i < 4; i++)
        schedule->timeSlots[i] = -1; // Initialize all time slots as empty

    // Assign Turing to the 10 AM slot
    schedule->timeSlots[0] = AlanTuring;





        printf("--------------------------------- METU Time Machine Scheduler --------------------------\n");
        printf("Select the scheduling technique:\n");
        printf("1. Pure backtracking search algorithm\n");
        printf("2. Backtracking search algorithm + forward checking\n");
        printf("3. Backtracking search algorithm + Arc Consistency\n");
        printf("4. Backtracking search algorithm + Degree Heuristic\n");
        printf("5. Backtracking search algorithm + MRV\n");
        printf("6. Backtracking search algorithm + Min-Conflict\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:

                printSchedule(schedule, pureBacktrackingSearch(schedule, 1));
                break;
            case 2:
                backtrackingSearchForwardChecking();
                break;
            case 3:
                backtrackingSearchArcConsistency();
                break;
            case 4:
                backtrackingSearchDegreeHeuristic();
                break;
            case 5:
                backtrackingSearchMRV();
                break;
            case 6:
                backtrackingSearchMinConflict();
                break;
            case 7:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n");

    } while (choice != 7);

    return 0;
}