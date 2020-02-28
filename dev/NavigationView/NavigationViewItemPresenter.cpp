// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

#include "pch.h"
#include "common.h"
#include "NavigationViewItemPresenter.h"
#include "NavigationViewItem.h"
#include "SharedHelpers.h"

static constexpr auto c_contentGrid = L"PresenterContentRootGrid"sv;
static constexpr auto c_expandCollapseChevron = L"ExpandCollapseChevron"sv;

NavigationViewItemPresenter::NavigationViewItemPresenter()
{
    SetDefaultStyleKey(this);
}

void NavigationViewItemPresenter::OnApplyTemplate()
{
    // Retrieve pointers to stable controls 
    m_helper.Init(*this);

    if (auto contentGrid = GetTemplateChildT<winrt::Grid>(c_contentGrid, *this))
    {
        m_contentGrid.set(contentGrid);
    }

    if (auto navigationViewItem = GetNavigationViewItem())
    {
        if (auto const expandCollapseChevron = GetTemplateChildT<winrt::Grid>(c_expandCollapseChevron, *this))
        {
            m_expandCollapseChevron.set(expandCollapseChevron);
            m_expandCollapseChevronTappedToken = expandCollapseChevron.Tapped({ navigationViewItem, &NavigationViewItem::OnExpandCollapseChevronTapped });
        }

        navigationViewItem->UpdateVisualStateNoTransition();
    }

    //Test
    if (auto const iconContentPresenter = GetTemplateChildT<winrt::ContentPresenter>(L"Icon", *this))
    {
        m_iconContentPresenter.set(iconContentPresenter);
        dataContextRevoker = iconContentPresenter.DataContextChanged(winrt::auto_revoke, { this, &NavigationViewItemPresenter::OnDataContextPropertyChanged });
        contentChangedRevoker = RegisterPropertyChanged(iconContentPresenter, winrt::ContentPresenter::ContentProperty(), { this, &NavigationViewItemPresenter::OnContentPropertyChanged });
    }

    UpdateMargin();
}

void NavigationViewItemPresenter::OnContentPropertyChanged(const winrt::DependencyObject& sender, const winrt::DependencyProperty& args)
{
    winrt::hstring TESTNAME = L"TESTNAME";
    if (auto itemName = GetNavigationViewItem())
    {
        TESTNAME = itemName->Name();
    }
    if (auto const iconContentPresenter = m_iconContentPresenter.get())
    {
        auto const testcontent = iconContentPresenter.Content();
        if (iconContentPresenter.Content() != Icon())
        {
            iconContentPresenter.Content(nullptr);
        }
    }
}

void NavigationViewItemPresenter::OnDataContextPropertyChanged(winrt::IInspectable const& sender, const winrt::DataContextChangedEventArgs& args)
{
    winrt::hstring TESTNAME = L"TESTNAME";
    auto const dataContext = args.NewValue();
    if (auto itemName = GetNavigationViewItem())
    {
        TESTNAME = itemName->Name();
    }
    //if(auto const iconContentPresenter = m_iconContentPresenter.get())
    //{
    //    auto const testcontent = iconContentPresenter.Content();
    //    if (!iconContentPresenter.Content() && args.NewValue())
    //    {
    //        iconContentPresenter.DataContext(nullptr);
    //    }
    //}
}

winrt::UIElement NavigationViewItemPresenter::GetSelectionIndicator()
{
    return m_helper.GetSelectionIndicator();  
}

bool NavigationViewItemPresenter::GoToElementStateCore(winrt::hstring const& state, bool useTransitions)
{
    // GoToElementStateCore: Update visualstate for itself.
    // VisualStateManager::GoToState: update visualstate for it's first child.

    // If NavigationViewItemPresenter is used, two sets of VisualStateGroups are supported. One set is help to switch the style and it's NavigationViewItemPresenter itself and defined in NavigationViewItem
    // Another set is defined in style for NavigationViewItemPresenter.
    // OnLeftNavigation, OnTopNavigationPrimary, OnTopNavigationOverflow only apply to itself.
    if (state == c_OnLeftNavigation || state == c_OnLeftNavigationReveal || state == c_OnTopNavigationPrimary
        || state == c_OnTopNavigationPrimaryReveal || state == c_OnTopNavigationOverflow)
    {
        return __super::GoToElementStateCore(state, useTransitions);
    }
    return winrt::VisualStateManager::GoToState(*this, state, useTransitions);
}

NavigationViewItem* NavigationViewItemPresenter::GetNavigationViewItem()
{
    NavigationViewItem* navigationViewItem = nullptr;

    winrt::DependencyObject obj = operator winrt::DependencyObject();

    if (auto item = SharedHelpers::GetAncestorOfType<winrt::NavigationViewItem>(winrt::VisualTreeHelper::GetParent(obj)))
    {
        navigationViewItem = winrt::get_self<NavigationViewItem>(item);
    }
    return navigationViewItem;
}

void NavigationViewItemPresenter::UpdateContentLeftIndentation(double leftIndentation)
{
    m_leftIndentation = leftIndentation;
    UpdateMargin();
}

void NavigationViewItemPresenter::UpdateMargin()
{
    if (auto const grid = m_contentGrid.get())
    {
        auto const oldGridMargin = grid.Margin();
        grid.Margin({ m_leftIndentation, oldGridMargin.Top, oldGridMargin.Right, oldGridMargin.Bottom });
    }
}

void NavigationViewItemPresenter::IsExpandCollapseChevronVisible(bool isVisible)
{
    auto const visibility = isVisible ? winrt::Visibility::Visible : winrt::Visibility::Collapsed;
    m_expandCollapseChevron.get().Visibility(visibility);
}
