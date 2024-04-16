#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100

char file_registry[MAX_FILES][256];
int file_count = 0;

// Helper function to add a file to the registry
void register_file(const char *filename)
{
    for (int i = 0; i < file_count; i++)
    {
        if (strcmp(file_registry[i], filename) == 0)
        {
            return; // File is already registered
        }
    }
    if (file_count < MAX_FILES)
    {
        strcpy(file_registry[file_count++], filename);
    }
}

// Helper function to remove a file from the registry
void deregister_file(const char *filename)
{
    for (int i = 0; i < file_count; i++)
    {
        if (strcmp(file_registry[i], filename) == 0)
        {
            for (int j = i; j < file_count - 1; j++)
            {
                strcpy(file_registry[j], file_registry[j + 1]);
            }
            file_count--;
            break;
        }
    }
}

// Function to mimic 'touch' command
void touch(const char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp != NULL)
    {
        printf("touch %s\n\"File already exist\"\n", filename);
        fclose(fp);
    }
    else
    {
        fp = fopen(filename, "w");
        if (fp == NULL)
        {
            perror("Error creating file");
        }
        else
        {
            printf("touch %s\n", filename);
            fclose(fp);
            register_file(filename);
        }
    }
}

// Function to mimic 'echo' command with redirection to file
void echo(const char *text, const char *filename)
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        perror("Error opening file");
    }
    else
    {
        fprintf(fp, "%s", text);
        fclose(fp);
        printf("echo %s > %s\n", text, filename);
    }
}

// Function to mimic 'cat' command
void cat(const char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        perror("Error reading file");
    }
    else
    {
        printf("cat %s\n", filename);
        char c;
        while ((c = fgetc(fp)) != EOF)
        {
            putchar(c);
        }
        putchar('\n');
        fclose(fp);
    }
}

// Function to mimic 'rm' command
void rm(const char *filename)
{
    if (remove(filename) != 0)
    {
        perror("Error deleting file");
    }
    else
    {
        printf("rm %s\n", filename);
        deregister_file(filename);
    }
}

// Function to mimic 'ls' command
void ls()
{
    printf("ls\n");
    if (file_count == 0)
    {
        printf("\n");
    }
    else
    {
        for (int i = 0; i < file_count; i++)
        {
            printf("%s\n", file_registry[i]);
        }
    }
}

int main()
{
    // Demonstration
    touch("example.txt");
    ls();
    touch("example.txt");
    cat("example.txt");
    echo("Hello, World!", "example.txt");
    cat("example.txt");
    rm("example.txt");
    ls();

    return 0;
}
