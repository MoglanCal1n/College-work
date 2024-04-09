#include "LocatarRepo.h"
#include "LocatarService.h"
#include "LocatarUI.h"
#include "Teste.h"

int main() {
    test_All();
    LocatarRepo rep;
    LocatarService serv{ rep };
    LocatarUI ui { serv };
    ui.run();
    return 0;
}
