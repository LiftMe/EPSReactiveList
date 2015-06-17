Pod::Spec.new do |s|
  s.name             = "EPSReactiveList"
  s.version          = "0.2"
  s.summary          = "Table and collection view controllers that automatically populates themselves, and animate the insertion and deletion of rows/items."
  
  s.homepage         = "https://github.com/LiftMe/EPSReactiveList"
  s.license          = "MIT"
  s.author           = { "Peter Stuart" => "peter@electricpeelsoftware.com" }
  s.source           = { :git => "https://github.com/LiftMe/EPSReactiveList.git", :tag => s.version.to_s }
  
  s.platform              = :ios, '7.0'
  s.ios.deployment_target = '7.0'
  s.requires_arc          = true

  s.source_files = 'Classes'

  s.public_header_files = 'Classes/*.h'
  s.framework = 'UIKit'
  s.dependency 'ReactiveCocoa', '~> 2.3'
end
