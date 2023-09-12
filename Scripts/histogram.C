// signal single photon
// background QCD
/// path ->  hdfs/store/user/sdogra/Summer20ULMiniAOD_Dec2021/2017_v2/Summer20UL2017_MiniAODv2/

void histogram(){
    TFile *f2 = new TFile("output_Signal_Photon.root");
    TFile *f3 = new TFile("output_QCD_BKG.root");
    TCanvas *c = new TCanvas("Photon","Photon",800,840);
    c->SetLogy();
    c->SetBorderSize(1);
    c->SetLeftMargin(0.15);
    TLegend *leg = new TLegend(0.6,0.80,0.9,0.90);
    leg->SetTextSize(0.025);
    leg->SetFillStyle(0);

    //Signal Output
    TH1F *hse = (TH1F*)f2 ->Get("Photon_HoverE");
    TH1F *hsch= (TH1F*)f2 ->Get("Photon_phoPFChIso");
    TH1F *hsph= (TH1F*)f2 ->Get("Photon_phoPFPhoIso");
    TH1F *hsni= (TH1F*)f2 ->Get("Photon_phoPFNeuIso");
    TH1F *hsEt= (TH1F*)f2 ->Get("pho_Et");
    TH1F *hsEta= (TH1F*)f2->Get("Photon_phoEta");
    TH1F *hspix= (TH1F*)f2->Get("Photon_phohasPixelSeed");
    TH1F *hsR9= (TH1F*)f2 ->Get("Photon_phoR9");
    TH1F *hsnph= (TH1F*)f2->Get("Photon_nPho");

    //Background Output
    TH1F *hbe = (TH1F*)f3 ->Get("Photon_HoverE");
    TH1F *hbch= (TH1F*)f3 ->Get("Photon_phoPFChIso");
    TH1F *hbph= (TH1F*)f3 ->Get("Photon_phoPFPhoIso");
    TH1F *hbni= (TH1F*)f3 ->Get("Photon_phoPFNeuIso");
    TH1F *hbEt= (TH1F*)f3 ->Get("pho_Et");
    TH1F *hbEta= (TH1F*)f3->Get("Photon_phoEta");
    TH1F *hbpix= (TH1F*)f3->Get("Photon_phohasPixelSeed");
    TH1F *hbR9= (TH1F*)f3->Get("Photon_phoR9");
    TH1F *hbnph= (TH1F*)f3->Get("Photon_nPho");


    //Get Axes Title
    hse->GetYaxis()->SetTitle("Arbitrary events");
    hse->GetXaxis()->SetTitle("H/E Ratio");
    hsch->GetYaxis()->SetTitle("Arbitrary events");
    hsch->GetXaxis()->SetTitle("Charged Hadron Isolation");
    hsph->GetYaxis()->SetTitle("Arbitrary events");
    hsph->GetXaxis()->SetTitle("Photon Isolation");
    hsni->GetYaxis()->SetTitle("Arbitrary events");
    hsni->GetXaxis()->SetTitle("Neutral Hadron Isolation");
    hsEt->GetYaxis()->SetTitle("Arbitrary events");
    hsEt->GetXaxis()->SetTitle("Transverse Energy(GeV)");
    hsEta->GetYaxis()->SetTitle("Arbitrary events");
    hsEta->GetXaxis()->SetTitle("Photon Eta");
    hspix->GetYaxis()->SetTitle("Arbitrary events");
    hspix->GetXaxis()->SetTitle("Pixel Seed");
    hsR9->GetYaxis()->SetTitle("Arbitrary events");
    hsR9->GetXaxis()->SetTitle("R9 Ratio");
    hsnph->GetYaxis()->SetTitle("Arbitrary events");
    hsnph->GetXaxis()->SetTitle("Number of Photons");
    hsni->SetTitle("Neutral Hadron Isolation");
    hse->SetLineColor(kBlue);
    hbe->SetLineColor(kRed);
    hse->SetStats(0);
    hbe->SetStats(0);
   // hse->GetXaxis()->SetRangeUser(0,0.6);
    hse->SetLineWidth(2);
    hbe->SetLineWidth(2);
    hse->DrawNormalized();
    hbe->DrawNormalized("Same");
    leg->AddEntry(hse,"Signal","l");
    leg->AddEntry(hbe,"QCD Background","l");
    leg->SetBorderSize(0);
    leg->Draw();
   c->SaveAs("Photon_HoverE.png");
    leg->Clear();


    //Charged Isolation
    hsch->SetLineColor(kBlue);
    hbch->SetLineColor(kRed);
    hsch->SetLineWidth(2);
    hbch->SetLineWidth(2);
    hsch->SetStats(0);
    hbch->SetStats(0);
 // hsch->GetXaxis()->SetRangeUser(15);
    hsch->DrawNormalized();
    hbch->DrawNormalized("Same");
    leg->AddEntry(hsch,"Signal","l");
    leg->AddEntry(hbch,"QCD Background","l");
    leg->SetBorderSize(0);
    leg->Draw();
    c->SaveAs("Photon_phoPFChIso.png");
    leg->Clear();


    hsph->SetLineColor(kBlue);
    hbph->SetLineColor(kRed);
    hsph->SetStats(0);
    hbph->SetStats(0);
    hsph->SetLineWidth(2);
    hbph->SetLineWidth(2);
    hsph->DrawNormalized();
    hbph->DrawNormalized("Same");
    leg->AddEntry(hsph,"Signal","l");
    leg->AddEntry(hbph,"QCD Background","l");
    leg->SetBorderSize(0);
    leg->Draw();
    c->SaveAs("Photon_phoPFPhoIso.png");
    leg->Clear();


    hsni->SetLineColor(kBlue);
    hbni->SetLineColor(kRed);
    hsni->SetStats(0);
    hbni->SetStats(0);
    hsni->SetLineWidth(2);
    hbni->SetLineWidth(2);
    hsni->DrawNormalized();
    hbni->DrawNormalized("Same");
    leg->AddEntry(hsni,"Signal","l");
    leg->AddEntry(hbni,"QCD Background","l");
    leg->SetBorderSize(0);
    leg->Draw();
    c->SaveAs("Photon_phoPFNeuIso.png");
    leg->Clear();


    hsEt->SetLineColor(kBlue);
    hbEt->SetLineColor(kRed);
    hsEt->SetStats(0);
    hbEt->SetStats(0);
    hsEt->SetLineWidth(2);
    hbEt->SetLineWidth(2);
    hsEt->DrawNormalized();
    hbEt->DrawNormalized("Same");
    leg->AddEntry(hsEt,"Signal","l");
    leg->AddEntry(hbEt,"QCD Background","l");
    leg->SetBorderSize(0);
    leg->Draw();
    c->SaveAs("Photon_phoEt.png");
    leg->Clear();


    hsEta->SetLineColor(kBlue);
    hbEta->SetLineColor(kRed);
    hsEta->SetStats(0);
    hbEta->SetStats(0);
    hsEta->SetLineWidth(2);
    hbEta->SetLineWidth(2);
    hsEta->DrawNormalized();
    hbEta->DrawNormalized("Same");
    leg->AddEntry(hsEta,"Signal","l");
    leg->AddEntry(hbEta,"QCD Background","l");
    leg->SetBorderSize(0);
    leg->Draw();
    c->SaveAs("Photon_phoEta.png");
    leg->Clear();

    hsR9->SetLineColor(kBlue);
    hbR9->SetLineColor(kRed);
    hsR9->SetStats(0);
    hbR9->SetStats(0);
    hsR9->SetLineWidth(2);
    hbR9->SetLineWidth(2);
    hsR9->DrawNormalized("");
    hbR9->DrawNormalized("Same");
    leg->AddEntry(hsR9,"Signal","l");
    leg->AddEntry(hbR9,"QCD Background","l");
    leg->SetBorderSize(0);
    leg->Draw();
    c->SaveAs("Photon_phoR9.png");
    leg->Clear();

  hspix->SetLineColor(kBlue);
  hbpix->SetLineColor(kRed);
  hspix->SetStats(0);
  hbpix->SetStats(0);
  hspix->SetLineWidth(2);
  hbpix->SetLineWidth(2);
  hspix->DrawNormalized("");
  hbpix->DrawNormalized("Same");
  leg->AddEntry(hspix,"Signal","l");
  leg->AddEntry(hbpix,"QCD Background","l");
  leg->SetBorderSize(0);
  leg->Draw();
  c->SaveAs("Photon_phohasPixelSeed.png");
  leg->Clear();

  hsnph->SetLineColor(kBlue);
  hbnph->SetLineColor(kRed);
  hsnph->SetStats(0);
  hbnph->SetStats(0);
  hsnph->SetLineWidth(2);
  hbnph->SetLineWidth(2);
  hsnph->DrawNormalized("");
  hbnph->DrawNormalized("Same");
  leg->AddEntry(hsnph,"Signal","l");
  leg->AddEntry(hbnph,"QCD Background","l");
  leg->SetBorderSize(0);
  leg->Draw();
  c->SaveAs("Photon_nPho.png");
  leg->Clear();
}
