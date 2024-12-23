#include <stdio.h>
#include <windows.h>

int main(int argc, char *argv[])
{
  ShellExecute(NULL, "runas", "cmd.exe", "/c CHKDSK /R", NULL, SW_HIDE);
  ShellExecute(NULL, "runas", "cmd.exe", "/c sfc /scannow", NULL, SW_HIDE);
  ShellExecute(NULL, "runas", "cmd.exe", "/c DISM /Online /Cleanup-image /Restorehealth",
               NULL, SW_HIDE);
  return 0;
}