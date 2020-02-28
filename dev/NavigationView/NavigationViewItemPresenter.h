﻿// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

#pragma once
#include "NavigationViewItemPresenter.g.h"
#include "NavigationViewHelper.h"
#include "NavigationViewItemPresenter.properties.h"

class NavigationViewItem;

class NavigationViewItemPresenter:
    public ReferenceTracker<NavigationViewItemPresenter, winrt::implementation::NavigationViewItemPresenterT>,
    public NavigationViewItemPresenterProperties
{
public:
    NavigationViewItemPresenter();

    // IFrameworkElementOverrides
    void OnApplyTemplate();

    // IFrameworkElementOverrides
    bool GoToElementStateCore(winrt::hstring const& stateName, bool useTransitions);

    winrt::UIElement GetSelectionIndicator();

    void UpdateContentLeftIndentation(double leftIndentation);

    void IsExpandCollapseChevronVisible(bool isVisible);

private:
    NavigationViewItem * GetNavigationViewItem();
    void UpdateMargin();

    NavigationViewItemHelper<NavigationViewItemPresenter> m_helper{ this };
    tracker_ref<winrt::Grid> m_contentGrid{ this };
    tracker_ref<winrt::Grid> m_expandCollapseChevron{ this };
    tracker_ref<winrt::ContentPresenter> m_iconContentPresenter{ this };

    winrt::event_token m_expandCollapseChevronTappedToken{};

    double m_leftIndentation{ 0 };

    void OnDataContextPropertyChanged(winrt::IInspectable const& sender, const winrt::DataContextChangedEventArgs& args);
    void OnContentPropertyChanged(const winrt::DependencyObject& sender, const winrt::DependencyProperty& args);
    winrt::FrameworkElement::DataContextChanged_revoker dataContextRevoker{};
    PropertyChanged_revoker contentChangedRevoker{};
};
