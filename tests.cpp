#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

// add your tests here

TEST_CASE("Non encryptable") {
  CHECK(solve("!?@") == "!?@");
  CHECK(solve("123") == "123");
  CHECK(solve("  ") == "  ");
  CHECK(solve("/09123") == "/09123");
}

TEST_CASE("Easy Base Cases") {
  CHECK(solve("llllllllllllllllllllllllll") == "eeeeeeeeeeeeeeeeeeeeeeeeee");
}

TEST_CASE("Rotation of Zero") {
  CHECK(solve("A pangram, or holoalphabetic sentence, is a sentence that contains every letter of the alphabet at least once. The most famous pangram is probably the thirty-five-letter-long “The quick brown fox jumps over the lazy dog,” which has been used to test typing equipment since at least the late 1800s. Pangrams are an important tool for testing typing equipment and compactly showing off every letter of a typeface; trying to pack every letter into as short a sentence as possible is also a sort of sport among linguists and puzzle-solvers.") == "A pangram, or holoalphabetic sentence, is a sentence that contains every letter of the alphabet at least once. The most famous pangram is probably the thirty-five-letter-long “The quick brown fox jumps over the lazy dog,” which has been used to test typing equipment since at least the late 1800s. Pangrams are an important tool for testing typing equipment and compactly showing off every letter of a typeface; trying to pack every letter into as short a sentence as possible is also a sort of sport among linguists and puzzle-solvers.");
  CHECK(solve("Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.") == "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.");
}

TEST_CASE("Encrypted Strings W Random Shifts") {
  CHECK(solve("Pa pz h svun lzahispzolk mhja aoha h ylhkly dpss il kpzayhjalk if aol ylhkhisl jvualua vm h whnl dolu svvrpun ha paz shfvba. Aol wvpua vm bzpun Svylt Pwzbt pz aoha pa ohz h tvyl-vy-slzz uvyths kpzaypibapvu vm slaalyz, hz vwwvzlk av bzpun 'Jvualua olyl, jvualua olyl', thrpun pa svvr sprl ylhkhisl Lunspzo. Thuf klzravw wbispzopun whjrhnlz huk dli whnl lkpavyz uvd bzl Svylt Pwzbt hz aolpy klmhbsa tvkls alea, huk h zlhyjo mvy 'svylt pwzbt' dpss bujvcly thuf dli zpalz zapss pu aolpy pumhujf. Chypvbz clyzpvuz ohcl lcvsclk vcly aol flhyz, zvtlaptlz if hjjpklua, zvtlaptlz vu wbywvzl (puqljalk obtvby huk aol sprl).") == "It is a long established fact that a reader will be distracted by the readable content of a page when looking at its layout. The point of using Lorem Ipsum is that it has a more-or-less normal distribution of letters, as opposed to using 'Content here, content here', making it look like readable English. Many desktop publishing packages and web page editors now use Lorem Ipsum as their default model text, and a search for 'lorem ipsum' will uncover many web sites still in their infancy. Various versions have evolved over the years, sometimes by accident, sometimes on purpose (injected humour and the like).");
  CHECK(solve("Gurer ner znal inevngvbaf bs cnffntrf bs Yberz Vcfhz ninvynoyr, ohg gur znwbevgl unir fhssrerq nygrengvba va fbzr sbez, ol vawrpgrq uhzbhe, be enaqbzvfrq jbeqf juvpu qba'g ybbx rira fyvtugyl oryvrinoyr. Vs lbh ner tbvat gb hfr n cnffntr bs Yberz Vcfhz, lbh arrq gb or fher gurer vfa'g nalguvat rzoneenffvat uvqqra va gur zvqqyr bs grkg. Nyy gur Yberz Vcfhz trarengbef ba gur Vagrearg graq gb ercrng cerqrsvarq puhaxf nf arprffnel, znxvat guvf gur svefg gehr trarengbe ba gur Vagrearg. Vg hfrf n qvpgvbanel bs bire 200 Yngva jbeqf, pbzovarq jvgu n unaqshy bs zbqry fragrapr fgehpgherf, gb trarengr Yberz Vcfhz juvpu ybbxf ernfbanoyr. Gur trarengrq Yberz Vcfhz vf gurersber nyjnlf serr sebz ercrgvgvba, vawrpgrq uhzbhe, be aba-punenpgrevfgvp jbeqf rgp.") == "There are many variations of passages of Lorem Ipsum available, but the majority have suffered alteration in some form, by injected humour, or randomised words which don't look even slightly believable. If you are going to use a passage of Lorem Ipsum, you need to be sure there isn't anything embarrassing hidden in the middle of text. All the Lorem Ipsum generators on the Internet tend to repeat predefined chunks as necessary, making this the first true generator on the Internet. It uses a dictionary of over 200 Latin words, combined with a handful of model sentence structures, to generate Lorem Ipsum which looks reasonable. The generated Lorem Ipsum is therefore always free from repetition, injected humour, or non-characteristic words etc.");
}

TEST_CASE("More tests; shorter strings") {
  CHECK(solve("Ftq tmdq imxwqp gzqhqzxk az ftq yagzfmuz damp.") == "The hare walked unevenly on the mountain road.");
  CHECK(solve("S kdo dro lbygxso kxn dro zkxmkuo iocdobnki.") == "I ate the brownie and the pancake yesterday.");
  CHECK(solve("Awumpwe mdmzg lig nmmta bpm aium jcb vwb ycqbm.") == "Somehow every day feels the same but not quite.");
  CHECK(solve("Nzwabml ntisma bpmg'zm ozmib!") == "Frosted flakes they're great!");
}
