#include <iostream>
#include <cmath>
#include <array>
#include "funcs.h"

int main()
{
  std::cout << "Simple Cases (No rotation)" << std::endl;
  std::cout << "-----------------------------" << std::endl;
  std::cout << "Let a = 'A pangram, or holoalphabetic sentence, is a sentence that contains every letter of the alphabet at least once. The most famous pangram is probably the thirty-five-letter-long “The quick brown fox jumps over the lazy dog,” which has been used to test typing equipment since at least the late 1800s. Pangrams are an important tool for testing typing equipment and compactly showing off every letter of a typeface; trying to pack every letter into as short a sentence as possible is also a sort of sport among linguists and puzzle-solvers.'" << std::endl;
  std::cout << "solve(a);";
  std::cout << solve("A pangram, or holoalphabetic sentence, is a sentence that contains every letter of the alphabet at least once. The most famous pangram is probably the thirty-five-letter-long “The quick brown fox jumps over the lazy dog,” which has been used to test typing equipment since at least the late 1800s. Pangrams are an important tool for testing typing equipment and compactly showing off every letter of a typeface; trying to pack every letter into as short a sentence as possible is also a sort of sport among linguists and puzzle-solvers.") << std::endl;
  std::cout << std::endl << std::endl;
  std::cout << "solve('Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.')" << std::endl << std::endl;
  std::cout << solve("Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.") << std::endl << std::endl;
  std::cout << std::endl << std::endl;
  std::cout << "Cases for common words(e):" << std::endl;
  std::cout << "-----------------------------" << std::endl;
  std::cout << "solve('llllllllllllllllllllllllll');" << std::endl;
  std::cout << solve("llllllllllllllllllllllllll") << std::endl;
  std::cout << std::endl << std::endl;
  std::cout << "More complex cases W random rotations:" << std::endl;
  std::cout << "-----------------------------" << std::endl;
  std::cout << "solve('Pa pz h svun lzahispzolk mhja aoha h ylhkly dpss il kpzayhjalk if aol ylhkhisl jvualua vm h whnl dolu svvrpun ha paz shfvba. Aol wvpua vm bzpun Svylt Pwzbt pz aoha pa ohz h tvyl-vy-slzz uvyths kpzaypibapvu vm slaalyz, hz vwwvzlk av bzpun 'Jvualua olyl, jvualua olyl', thrpun pa svvr sprl ylhkhisl Lunspzo. Thuf klzravw wbispzopun whjrhnlz huk dli whnl lkpavyz uvd bzl Svylt Pwzbt hz aolpy klmhbsa tvkls alea, huk h zlhyjo mvy 'svylt pwzbt' dpss bujvcly thuf dli zpalz zapss pu aolpy pumhujf. Chypvbz clyzpvuz ohcl lcvsclk vcly aol flhyz, zvtlaptlz if hjjpklua, zvtlaptlz vu wbywvzl (puqljalk obtvby huk aol sprl).');" << std::endl;
  std::cout << solve("Pa pz h svun lzahispzolk mhja aoha h ylhkly dpss il kpzayhjalk if aol ylhkhisl jvualua vm h whnl dolu svvrpun ha paz shfvba. Aol wvpua vm bzpun Svylt Pwzbt pz aoha pa ohz h tvyl-vy-slzz uvyths kpzaypibapvu vm slaalyz, hz vwwvzlk av bzpun 'Jvualua olyl, jvualua olyl', thrpun pa svvr sprl ylhkhisl Lunspzo. Thuf klzravw wbispzopun whjrhnlz huk dli whnl lkpavyz uvd bzl Svylt Pwzbt hz aolpy klmhbsa tvkls alea, huk h zlhyjo mvy 'svylt pwzbt' dpss bujvcly thuf dli zpalz zapss pu aolpy pumhujf. Chypvbz clyzpvuz ohcl lcvsclk vcly aol flhyz, zvtlaptlz if hjjpklua, zvtlaptlz vu wbywvzl (puqljalk obtvby huk aol sprl).") << std::endl;
  std::cout << std::endl << std::endl;
  std::cout << "solve('Gurer ner znal inevngvbaf bs cnffntrf bs Yberz Vcfhz ninvynoyr, ohg gur znwbevgl unir fhssrerq nygrengvba va fbzr sbez, ol vawrpgrq uhzbhe, be enaqbzvfrq jbeqf juvpu qba'g ybbx rira fyvtugyl oryvrinoyr. Vs lbh ner tbvat gb hfr n cnffntr bs Yberz Vcfhz, lbh arrq gb or fher gurer vfa'g nalguvat rzoneenffvat uvqqra va gur zvqqyr bs grkg. Nyy gur Yberz Vcfhz trarengbef ba gur Vagrearg graq gb ercrng cerqrsvarq puhaxf nf arprffnel, znxvat guvf gur svefg gehr trarengbe ba gur Vagrearg. Vg hfrf n qvpgvbanel bs bire 200 Yngva jbeqf, pbzovarq jvgu n unaqshy bs zbqry fragrapr fgehpgherf, gb trarengr Yberz Vcfhz juvpu ybbxf ernfbanoyr. Gur trarengrq Yberz Vcfhz vf gurersber nyjnlf serr sebz ercrgvgvba, vawrpgrq uhzbhe, be aba-punenpgrevfgvp jbeqf rgp.');" << std::endl;
  std::cout << solve("Gurer ner znal inevngvbaf bs cnffntrf bs Yberz Vcfhz ninvynoyr, ohg gur znwbevgl unir fhssrerq nygrengvba va fbzr sbez, ol vawrpgrq uhzbhe, be enaqbzvfrq jbeqf juvpu qba'g ybbx rira fyvtugyl oryvrinoyr. Vs lbh ner tbvat gb hfr n cnffntr bs Yberz Vcfhz, lbh arrq gb or fher gurer vfa'g nalguvat rzoneenffvat uvqqra va gur zvqqyr bs grkg. Nyy gur Yberz Vcfhz trarengbef ba gur Vagrearg graq gb ercrng cerqrsvarq puhaxf nf arprffnel, znxvat guvf gur svefg gehr trarengbe ba gur Vagrearg. Vg hfrf n qvpgvbanel bs bire 200 Yngva jbeqf, pbzovarq jvgu n unaqshy bs zbqry fragrapr fgehpgherf, gb trarengr Yberz Vcfhz juvpu ybbxf ernfbanoyr. Gur trarengrq Yberz Vcfhz vf gurersber nyjnlf serr sebz ercrgvgvba, vawrpgrq uhzbhe, be aba-punenpgrevfgvp jbeqf rgp.");
  std::cout << std::endl << std::endl;
  return 0;
}
