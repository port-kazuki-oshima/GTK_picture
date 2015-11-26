#include <gtk/gtk.h>

/* ボタンを押した時の処理 */

void button_was_clicked(GtkWidget *widget, gpointer data)
{
  g_print("Hello World Button is pushed!\n");
}

gint CloseAppWindow (GtkWidget *widget, gpointer gdata)
{
  g_print("QUitting ... ?n");
  gtk_main_quit();

  /* 終了作業を継続 */
  return(FALSE);
}

int main(int argc, char *argv[]) 
{
    GtkWidget *window;
    GtkWidget *button;

    /* 初期化： ロケール設定 */ 
    gtk_set_locale();

    /* 初期化： オプションの処理 */
    gtk_init( &argc, &argv );

    /* 初期化： rc ファイルの読み込み */
    gtk_rc_parse("./gtkrc");

    /* トップレベルウィンドウを生成 */
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_signal_connect(GTK_OBJECT(window), "delete_event",
		       GTK_SIGNAL_FUNC(CloseAppWindow), NULL);

    /* コンテナ内のオブジェクトの周りにすき間を作成 */
    gtk_container_border_width(GTK_CONTAINER(window), 15);

    /* ボタンの作成 */
    button = gtk_button_new_with_label("Hello, World.\n");
    
    g_signal_connect(GTK_OBJECT(button), "clicked",
		       GTK_SIGNAL_FUNC(button_was_clicked), NULL);

    /* ボタンの配置 */
    gtk_container_add(GTK_CONTAINER(window), button);
    
    /* ボタンの表示 */
    gtk_widget_show(button);

    /* ウィンドウの表示 */
    gtk_widget_show(window);

    /* */
    gtk_main();

    /* 終了ステータスコード */

    return 0;
}
