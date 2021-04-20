namespace mesnyankin
{
    struct Mountain {
        char Name[30];
        int altitude;
        int latitude;
        int longtitude;
    };

    int createBinaryFile(const int arg, char *arguments[]);
    int findRecord(const int arg, char *arguments[]);
    int correctFile(const int arg, char *arguments[]);
}