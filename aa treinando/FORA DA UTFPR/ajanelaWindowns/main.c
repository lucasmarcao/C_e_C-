#include <windows.h>
#include <commctrl.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  switch (msg)
  {
  case WM_CLOSE:
    DestroyWindow(hwnd);
    break;
  case WM_DESTROY:
    PostQuitMessage(0);
    break;

  default:
    return DefWindowProc(hwnd, msg, wParam, lParam);
  }
  return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
  WNDCLASSEX wc;
  HWND hwnd;
  MSG msg;
  // Registra a classe da janela
  wc.cbSize = sizeof(WNDCLASSEX);
  wc.style = 0;
  wc.lpfnWndProc = WndProc;
  wc.cbClsExtra = 0;
  wc.cbWndExtra = 0;
  wc.hInstance = hInstance;
  wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
  wc.hCursor = LoadCursor(NULL, IDC_ARROW);
  wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
  wc.lpszMenuName = NULL;
  wc.lpszClassName = "MinhaJanela";
  wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
  if (!RegisterClassEx(&wc))
  {
    MessageBox(NULL, "Falha ao registrar a classe da janela!", "Erro", MB_ICONEXCLAMATION | MB_OK);
    return 0;
  }

  // Cria a janela
  hwnd = CreateWindowEx(
      WS_EX_CLIENTEDGE,
      "MinhaJanela",
      "Minha Janela",
      WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, CW_USEDEFAULT, 500, 400,
      NULL, NULL, hInstance, NULL);

  // Cria o label "Nome"
  HWND hLabelNome = CreateWindowEx(
      0, "STATIC", "Nome:", WS_CHILD | WS_VISIBLE | WS_BORDER,
      12, 10, 70, 20,
      hwnd, NULL, hInstance, NULL);

  // Cria a caixa de texto para o nome
  HWND hTextNome = CreateWindowEx(
      WS_EX_CLIENTEDGE, "EDIT", "", WS_CHILD | WS_VISIBLE | WS_BORDER,
      72, 10, 150, 20,
      hwnd, NULL, hInstance, NULL);

  // Cria o label "Cpf"
  HWND hLabelCpf = CreateWindowEx(
      0, "STATIC", "Cpf:", WS_CHILD | WS_VISIBLE | WS_BORDER,
      12, 40, 70, 20,
      hwnd, NULL, hInstance, NULL);

  // Cria a caixa de texto para o Cpf
  HWND hTextCpf = CreateWindowEx(
      WS_EX_CLIENTEDGE, "EDIT", "", WS_CHILD | WS_VISIBLE | WS_BORDER,
      72, 40, 150, 20,
      hwnd, NULL, hInstance, NULL);

  // Cria o label "Idade"
  HWND hLabelIdade = CreateWindowEx(
      0, "STATIC", "Idade:", WS_CHILD | WS_VISIBLE | WS_BORDER,
      12, 70, 70, 20,
      hwnd, NULL, hInstance, NULL);

  // Cria a caixa de texto para a idade
  HWND hTextIdade = CreateWindowEx(
      WS_EX_CLIENTEDGE, "EDIT", "", WS_CHILD | WS_VISIBLE | WS_BORDER,
      72, 70, 150, 20,
      hwnd, NULL, hInstance, NULL);

  // Cria o botão "Inserir" com o estilo "BS_PUSHBUTTON"
  HWND hBtnInserir = CreateWindowEx(
      0, "BUTTON", "Inserir", WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_DEFPUSHBUTTON,
      380, 10, 80, 30,
      hwnd, NULL, hInstance, NULL);

  // Cria o botão "Listar"
  HWND hBtnListar = CreateWindowEx(
      0, "BUTTON", "Listar", WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_DEFPUSHBUTTON,
      380, 50, 80, 30,
      hwnd, NULL, hInstance, NULL);

  // Cria o botão "Atualizar"
  HWND hBtnAtualizar = CreateWindowEx(
      0, "BUTTON", "Atualizar", WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_DEFPUSHBUTTON,
      290, 10, 80, 30,
      hwnd, NULL, hInstance, NULL);

  // Cria o botão "Excluir"
  HWND hBtnExcluir = CreateWindowEx(
      0, "BUTTON", "Excluir", WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_DEFPUSHBUTTON,
      290, 50, 80, 30,
      hwnd, NULL, hInstance, NULL);

  // Cria o controle de tabela (table control)
  HWND hTable = CreateWindowEx(
      WS_EX_CLIENTEDGE, WC_LISTVIEW, "", WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT | LVS_SINGLESEL,
      10, 100, 450, 150,
      hwnd, NULL, hInstance, NULL);

  // Adiciona as colunas "Nome" e "Idade" à tabela
  LVCOLUMN lvc;
  lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
  lvc.fmt = LVCFMT_CENTER;
  lvc.cx = 148;
  lvc.pszText = "Nome";
  lvc.iSubItem = 0;
  ListView_InsertColumn(hTable, 0, &lvc);
  lvc.pszText = "Idade";
  lvc.iSubItem = 1;
  ListView_InsertColumn(hTable, 1, &lvc);
  lvc.pszText = "Cpf";
  lvc.iSubItem = 2;
  ListView_InsertColumn(hTable, 2, &lvc);

  // Insere uma nova linha na tabela
  LVITEM lvi;
  lvi.mask = LVIF_TEXT;
  lvi.iItem = 0;         // Índice da linha (0 para adicionar na primeira linha)
  lvi.iSubItem = 0;      // Índice da coluna (0 para a primeira coluna)
  lvi.pszText = "lucas"; // Texto da célula
  ListView_InsertItem(hTable, &lvi);

  // Atribui o valor "18" à célula da coluna "Idade"
  lvi.iSubItem = 1;
  lvi.pszText = "18";
  ListView_SetItem(hTable, &lvi);

  lvi.iSubItem = 2;
  lvi.pszText = "981.244.189-11";
  ListView_SetItem(hTable, &lvi);

  // kkkkkk
  // Insere uma nova linha na tabela
  lvi.iItem = 1; // Índice da linha (1 para adicionar na segunda linha)
  lvi.iSubItem = 0;
  lvi.pszText = "joao";
  ListView_InsertItem(hTable, &lvi);

  // Atribui o valor "25" à célula da coluna "Idade"
  lvi.iSubItem = 1;
  lvi.pszText = "25";
  ListView_SetItem(hTable, &lvi);

  lvi.iSubItem = 2;
  lvi.pszText = "923.331.189-21";
  ListView_SetItem(hTable, &lvi);

  if (hwnd == NULL)
  {
    MessageBox(NULL, "Falha ao criar a janela!", "Erro", MB_ICONEXCLAMATION | MB_OK);
    return 0;
  }

  // Obtém o tamanho da tela
  int screenWidth = GetSystemMetrics(SM_CXSCREEN);
  int screenHeight = GetSystemMetrics(SM_CYSCREEN);

  // Calcula a posição x e y da janela de modo que ela fique no centro da tela
  int x = (screenWidth - 500) / 2;
  int y = (screenHeight - 400) / 2;

  // Define a posição da janela
  SetWindowPos(hwnd, 0, x, y, 0, 0, SWP_NOZORDER | SWP_NOSIZE);

  ShowWindow(hwnd, nShowCmd);
  UpdateWindow(hwnd);

  // Loop de mensagem
  while (GetMessage(&msg, NULL, 0, 0) > 0)
  {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  return msg.wParam;
}
