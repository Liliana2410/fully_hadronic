#include <iostream>
#include <vector>
#include <string>
#include <TH1F.h>
using namespace std;

void plots()
{
    vector<std::string> names_files { "bkg1.root", "bkg2.root", "signal1.root"};

    vector<std::string> names {"t#bar{t}h", "t#bar{t}b#bar{b}/h", "t#bar{t}Z', m(Z')= 1000 GeV"};

    vector<std::string> plots { "Pairs", "Pairs_b", "Smallest_DR_dijet", "Smallest_DR_b_dijet", "Mother_Particles_dijets"};

    vector<std::string> plots_names { "Pairs", "Pairs_{b}",  "Smallest DR dijet", "Smallest DR b dijet", "Mother Particles dijets"};
   

    vector<std::string> x_labels { "Pairs of jets", "Pairs of b-dijets", " ", " ", " "};
    
    //"(1,2),(3,4)", "(1,3),(2,4)", "(1,4),(2,3)",
    // "(b_{1}j_{1}j_{2}),(b_{2}j_{3}j_{4})", "(b_{2}j_{1}j_{2}),(b_{1}j_{3}j_{4})", "(b_{1}j_{1}j_{3}),(b_{2}j_{2}j_{4})", "(b_{2}j_{1}j_{3}),(b_{1}j_{2}j_{4})", "(b_{1}j_{1}j_{4}),(b_{2}j_{2}j_{3})", "(b_{2}j_{1}j_{4}),(b_{1}j_{2}j_{3})"

    //vector<std::string> plots {"deltaR_b1b2"};

    vector<int> colors {82, 5, 2, 4, 6};

    vector<int> linestyles {1, 1, 10, 1, 1};
    
      
     
    TList *l = new TList();
    for(int i=0; i<plots.size(); i++)
    {
        THStack *hs = new THStack("hs", " ");
        TCanvas *c2 = new TCanvas(plots[i].c_str(),"Histos",1280,1024);  
        Double_t x_1,x_2;
        Double_t y_1,y_2;
        if (plots[i]=="M_dijet1" || plots[i]=="M_b_dijet1" || plots[i]=="M_dijet1_not" || plots[i]=="M_dijet1_partially" || plots[i]=="M_dijet1_fully" || plots[i]=="M_b_dijet1_partially" || plots[i]=="M_b_dijet1_fully" ||  plots[i]=="M_dijet1" || plots[i]=="M_b_dijet1" || plots[i]=="M_dijet1_not" || plots[i]=="M_dijet1_partially" || plots[i]=="M_dijet1_fully" || plots[i]=="M_b_dijet1_partially" || plots[i]=="M_b_dijet1_fully" || plots[i]=="M_dijet2" || plots[i]=="M_dijet2_fully" || plots[i]=="M_dijet2_not" || plots[i]=="M_dijet2_partially" || plots[i]=="Pairs" || plots[i]=="Pairs_b"){
            x_1 = 0.15;
            x_2 = 0.35;
        }
        else{
            x_1 = 0.65;
            x_2 = 0.85;
        }
	if (plots[i]=="PHI_b_dijet1_partially" || plots[i]=="PHI_b_dijet1" || plots[i]=="PHI_b_dijet1_fully" || plots[i]=="PHI_b_dijet2_partially" || plots[i]=="PHI_b_dijet2" || plots[i]=="PHI_b_dijet2_fully" || plots[i]=="PHI_dijet1_partially" || plots[i]=="PHI_dijet1" || plots[i]=="PHI_dijet1_fully" || plots[i]=="PHI_dijet1_not" || plots[i]=="PHI_dijet2_partially" || plots[i]=="PHI_dijet2" || plots[i]=="PHI_dijet2_fully" || plots[i]=="PHI_dijet2_not" || plots[i]=="PHI_b1" || plots[i]=="PHI_b2"){
            y_1 = 0.25;
            y_2 = 0.45;
        }
        else{
            y_1 = 0.65;
            y_2 = 0.85;
        }
        auto legend = new TLegend(x_1,y_1,x_2,y_2);
    for (int j=0; j<names.size(); j++)
    {    
        TFile f(names_files[j].c_str());
        TH1F *h = (TH1F*)f.Get(plots[i].c_str());
        h->SetDirectory(0);
        h->SetLineColor(colors[j]);
        h->SetLineStyle(linestyles[j]);
        h->SetLineWidth(3);
        h->Scale(1.0/h->Integral());
   	legend->AddEntry(h,names[j].c_str(),"l");
        legend->SetBorderSize(0);
        hs->Add(h); 
    }   
        hs->Draw("NOSTACK HIST");
        hs->GetXaxis()->SetTitle(x_labels[i].c_str());
        hs->GetYaxis()->SetTitle("a.u.");
        legend->Draw();
        l->Add(c2);
        std::string filename = plots[i] + ".png";
        c2->SaveAs(filename.c_str());
    }
    
    TFile* Output = new TFile("joined.root", "RECREATE"); 
    l->Write();
    Output->Close();

    //PRUEBA *********************************************************
    
    vector<std::string> plots_names_new {"#delta#eta", "#delta#phi", "#Delta R"};
    vector<std::string> labels_new {"#delta#eta", "#delta#phi", "#Delta R"};
    vector<std::string> plots_DETA {"dETA_dijet1", "dETA_dijet2", "dETA_pair12", "dETA_pair13", "dETA_pair14","dETA_pair23", "dETA_pair24", "dETA_pair34"};
    vector<std::string> plots_DETA_names {"dETA_dijet1", "dETA_dijet2", "dETA_pair12", "dETA_pair13", "dETA_pair14","dETA_pair23", "dETA_pair24", "dETA_pair34"};
    vector<std::string> plots_DPHI { "dPHI_dijet1", "dPHI_dijet2", "dPHI_pair12", "dPHI_pair13", "dPHI_pair14","dPHI_pair23", "dPHI_pair24", "dPHI_pair34"};
    vector<std::string> plots_DPHI_names {"dPHI_dijet1", "dPHI_dijet2", "dPHI_pair12", "dPHI_pair13", "dPHI_pair14","dPHI_pair23", "dPHI_pair24", "dPHI_pair34"};
    vector<std::string> plots_DR {"dDR_dijet1", "dDR_dijet2", "dDR_pair12", "dDR_pair13", "dDR_pair14", "dDR_pair23", "dDR_pair24", "dDR_pair34"};
    vector<std::string> plots_DR_names {"dDR_dijet1", "dDR_dijet2", "dDR_pair12", "dDR_pair13", "dDR_pair14", "dDR_pair23", "dDR_pair24", "dDR_pair34"};
    
    vector<int> colors_2 {2, 3, 55, 4, 6, 8, 96, 7};

    vector<int> linestyles_2 {1, 1, 10, 10, 10, 10, 10, 10};
        TList *list = new TList();
  /* for(int i=0; i<plots_names_new.size(); i++)
    {
        THStack *hs_new = new THStack("hs_new", plots_names_new[i].c_str());
        TCanvas *c2_new = new TCanvas(plots_names_new[i].c_str(),"Histos",1280,1024);  
        Double_t x_1,x_2;
        Double_t y_1,y_2;
       
        x_1 = 0.65;
        x_2 = 0.85;
        
        y_1 = 0.65;
        y_2 = 0.85;
        
        auto legend = new TLegend(x_1,y_1,x_2,y_2);
        TFile f_new(names_files[0].c_str());
        
        if(i==0){
        	for(int j=0; j<plots_DETA.size(); j++){
        		TH1F *h_new = (TH1F*)f_new.Get(plots_DETA[j].c_str());
        		h_new->SetDirectory(0);
        		h_new->SetLineColor(colors_2[j]);
        		h_new->SetLineStyle(linestyles_2[j]);
        		h_new->SetLineWidth(2);
        		//h_new->Scale(1.0/h_new->Integral());
   			legend->AddEntry(h_new,plots_DETA_names[j].c_str(),"list");
        		legend->SetBorderSize(0);
        		hs_new->Add(h_new); 
     		}
     	}
     	if(i==1){
        	for(int j=0; j<plots_DPHI.size(); j++){
        		TH1F *h_new = (TH1F*)f_new.Get(plots_DPHI[j].c_str());
        		h_new->SetDirectory(0);
        		h_new->SetLineColor(colors_2[j]);
        		h_new->SetLineStyle(linestyles_2[j]);
        		h_new->SetLineWidth(2);
        		//h_new->Scale(1.0/h_new->Integral());
   			legend->AddEntry(h_new, plots_DPHI_names[j].c_str(),"list");
        		legend->SetBorderSize(0);
        		hs_new->Add(h_new); 
     		}
     	}
     	if(i==2){
        	for(int j=0; j<plots_DR.size(); j++){
        		TH1F *h_new = (TH1F*)f_new.Get(plots_DR[j].c_str());
        		h_new->SetDirectory(0);
        		h_new->SetLineColor(colors_2[j]);
        		h_new->SetLineStyle(linestyles_2[j]);
        		h_new->SetLineWidth(2);
        		//h_new->Scale(1.0/h_new->Integral());
   			legend->AddEntry(h_new,plots_DR_names[j].c_str(),"list");
        		legend->SetBorderSize(0);
        		hs_new->Add(h_new); 
     		}
     	}
        hs_new->Draw("NOSTACK HIST");
        hs_new->GetXaxis()->SetTitle(labels_new[i].c_str());
        hs_new->GetYaxis()->SetTitle("a.u.");
        legend->Draw();
        list->Add(c2_new);
        std::string filename = plots_names_new[i] + ".png";
        c2_new->SaveAs(filename.c_str());
    }
    vector<std::string> names_comparison { "signal1.root", "con_el_cpp_viejo_DR2_b_afuera_noayudo.root", "con_el_cpp_viejo_DR2_con_cargas_b_afuera_medio_ayudo.root", "con_el_cpp_viejo_DR3_con_cargas_b_afuera_no_ayudo.root", "con_el_cpp_viejo_sin_nuevos_criterios_b_afuera.root"};
   
    vector<std::string> plot_comparison {"Charge", "#Delta R = 2", "Charge and #Delta R =2", "Charge and #Delta R =3", "No criteria"};
   vector<int> colors_3 {1, 2, 3, 4, 5};
   vector<int> linestyle_3 {1, 10, 9, 10, 10};
   
    THStack *hs_3 = new THStack("hs_3", "Comparison Pairs");
    TCanvas *c2_3 = new TCanvas("Comparison Pairs","Histos",1280,1024);  
        Double_t x_1,x_2;
        Double_t y_1,y_2;
        
        auto legend = new TLegend(0.65,0.15,0.85,0.35);
        for(int i=0; i<names_comparison.size(); i++){
        	TFile f_3(names_comparison[i].c_str());
        	TH1F *h3 = (TH1F*)f_3.Get("Pairs_b");
        	h3->SetDirectory(0);
        	h3->SetLineColor(colors_3[i]);
	        h3->SetLineStyle(linestyle_3[i]);
        	h3->SetLineWidth(2);
        	//h3->Scale(1.0/h3->Integral());
	   	legend->AddEntry(h3, plot_comparison[i].c_str(),"list");
        	legend->SetBorderSize(0);
        	legend->SetHeader("Selection criteria used","C");
        	hs_3->Add(h3); 
        }
        hs_3->Draw("NOSTACK HIST");
        hs_3->GetXaxis()->SetTitle("Pairs");
        hs_3->GetYaxis()->SetTitle("a.u.");
        legend->Draw();
        list->Add(c2_3);
        std::string filename = "Comparison_pairs.png";
        c2_3->SaveAs(filename.c_str());
        
    TFile* Output_2 = new TFile("joined_2.root", "RECREATE"); 
    list->Write();
    Output_2->Close();*/
}
