#pragma once

#include "GenericListView.h"
#include "PEParser.h"

class DataDirectoriesView : public IGenericListViewCallback {
public:
	DataDirectoriesView(PEParser* parser);
	void Init(CListViewCtrl& lv);

	// IGenericListViewCallback
	int GetItemCount() override;
	CString GetItemText(int row, int col) override;
	bool Sort(int column, bool ascending) override;
	bool CanSort(int col) const override {
		return false;
	}

private:
	struct DataDirectory {
		CString Name;
		int Index;
		DWORD Address;
		DWORD Size;
	};
	PEParser* _parser;
	DataDirectory _dirs[15];
};

