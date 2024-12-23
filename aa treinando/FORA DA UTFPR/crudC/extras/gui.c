#include <gtk/gtk.h>


int main(int argc, char *argv[])
{
  GtkWidget *window;
  GtkWidget *grid;
  GtkWidget *label;
  GtkWidget *entry;
  GtkWidget *button;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Formulário de Pessoa");
  gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  grid = gtk_grid_new();
  gtk_container_add(GTK_CONTAINER(window), grid);

  label = gtk_label_new("Nome:");
  gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 1, 1);

  entry = gtk_entry_new();
  gtk_grid_attach(GTK_GRID(grid), entry, 1, 0, 1, 1);

  label = gtk_label_new("Idade:");
  gtk_grid_attach(GTK_GRID(grid), label, 0, 1, 1, 1);

  entry = gtk_entry_new();
  gtk_grid_attach(GTK_GRID(grid), entry, 1, 1, 1, 1);

  button = gtk_button_new_with_label("Cadastrar");
  gtk_grid_attach(GTK_GRID(grid), button, 0, 2, 2, 1);

  gtk_widget_show_all(window);
  gtk_main();

  return 0;
}
